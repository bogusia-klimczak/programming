#include "db_conn.h"

// INCLUDE BLOCK BEG
#include <iostream>
#include "add_func.h"
// INCLUDE BLOCK END

// NAMESPACE BLOCK BEG
using std::cout;
using namespace albdarion;
// NAMESPACE BLOCK END

// default constructor
ALB_ENGINE::ALB_ENGINE()
{
	DBUserID = 0;
	DBUserName = "";
	DBUserPassword = "";
	DBName = "";
}

// function that initiate database data into DBData
void ALB_ENGINE::initiate_database_data()
{
	string database_data_s = readFile(string(_ALB_DATABASE_ENGINE_FOLDER_NAME_) + "/" + DBName + "/" + DBName + ".data.json");
	json database_data_j = json::parse(database_data_s);

	DBData = database_data_j;
}

// checks is there a table with name _table_name at DBName database
bool ALB_ENGINE::exist_table(string _table_name)
{
	json tables_list = DBData["tables_list"];

	for (auto table_name : tables_list)
	{
		if (_table_name == table_name)
		{
			return true;
		}
	}

	return false;
}

// reads and returns data of table with name _table_name as json
json ALB_ENGINE::read_table(string _table_name)
{
	string table_data_s = readFile(string(_ALB_DATABASE_ENGINE_FOLDER_NAME_) + "/" + DBName + "/" + _table_name + ".data.json");
	json table_data_j = json::parse(table_data_s);

	return table_data_j;
}

// returns table configuration data such as information about columns (type, default value etc.)
json ALB_ENGINE::get_table_confing_data(string _table_name)
{
	string table_config_data_s = readFile(string(_ALB_DATABASE_ENGINE_FOLDER_NAME_) + "/" + DBName + "/" + _table_name + ".config.json");
	json table_config_data_j = json::parse(table_config_data_s);

	return table_config_data_j;
}

// returns all existing columns names in table _table_name
vector<string> ALB_ENGINE::get_all_existed_columns_names(string _table_name)
{
	json columns_confing_data = ALB_ENGINE::get_table_confing_data(_table_name)["columns_data"];
	vector<string> all_existed_columns_name = {};

	for (auto column_data : columns_confing_data)
	{
		all_existed_columns_name.push_back(column_data["name"]);
	}

	return all_existed_columns_name;
}

bool ALB_ENGINE::are_columns_existing_at_table(string _table_name, vector<string> _columns_names, vector<string>& _columns_do_not_exist)
{
	vector<string> all_existed_columns_name = ALB_ENGINE::get_all_existed_columns_names(_table_name);

	for (auto column_name : _columns_names)
	{
		if (!in_array(column_name, all_existed_columns_name))
		{
			_columns_do_not_exist.push_back(column_name);
		}
	}

	if (_columns_do_not_exist.empty())
		return true;

	return false;
}

vector<string> ALB_ENGINE::find_auto_inc_col_in_table(string _table_name)
{
	vector<string> res = {};

	json _table_columns_config = ALB_ENGINE::get_table_confing_data(_table_name)["columns_data"];

	for (auto elem : _table_columns_config)
	{
		if (elem["auto_increment"] == "yes")
		{
			res.push_back(elem["name"]);
		}
	}
	return res;
}

json ALB_ENGINE::find_column_config_data(string _table_name, string _column_name)
{
	json res;

	json _table_columns_config = ALB_ENGINE::get_table_confing_data(_table_name)["columns_data"];
	for (auto column_data : _table_columns_config)
	{
		if (column_data["name"] == _column_name)
		{
			res = column_data;
			break;
		}
	}

	return res;
}

int ALB_ENGINE::get_last_auto_inc_val(string _table_name)
{
	return ALB_ENGINE::get_table_confing_data(_table_name)["last_auto_inc_val"];
}

bool ALB_ENGINE::add_row_to_table(string _table_name, json row)
{
	json _table_data = read_table(_table_name);

	_table_data.push_back(row);

	string res_data = _table_data.dump(4);

	writeFile(string(_ALB_DATABASE_ENGINE_FOLDER_NAME_) + "/" + DBName + "/" + _table_name + ".data.json", res_data);

	return true;
}

// _DBName     - database name
// _DBUsername - username of user to connect to database
// _DBPassword - password to connect to database
ALB_ENGINE::ALB_ENGINE(string _DBName, string _DBUsername, string _DBPassword) : ALB_ENGINE()
{
	string db_users_data_str = readFile(string(_ALB_DATABASE_ENGINE_FOLDER_NAME_) + "/users.data.json");
	auto db_users_data = json::parse(db_users_data_str);
	for (unsigned i = 0; i < db_users_data.size(); i++)
	{
		if (db_users_data[i]["username"] == _DBUsername && db_users_data[i]["password"] == _DBPassword)
		{
			//cout << "Successfully logged as " << _DBUsername << "\n";

			DBUserID = db_users_data[i]["id"];
			DBUserName = db_users_data[i]["username"];
			DBUserPassword = db_users_data[i]["password"];

			break;
		}
		else
		{
			error("Wrong username or password!");
			abort();
		}
	}

	string db_databases_list_str = readFile(string(_ALB_DATABASE_ENGINE_FOLDER_NAME_) + "/databases.list.json");
	auto db_databases_list = json::parse(db_databases_list_str);
	int countOfParsedDatabases = 0;
	for (unsigned i = 0; i < db_databases_list.size(); i++)
	{
		if (db_databases_list[i]["name"] == _DBName)
		{
			//cout << "Successfully connected to " << _DBName << "\n";

			DBName = db_databases_list[i]["name"];

			break;
		}
		else
		{
			countOfParsedDatabases++;
		}
	}

	if (db_databases_list.size() == countOfParsedDatabases)
	{
		error("Wrong database name!");
		abort();
	}

	initiate_database_data();
}

// _QUERY - sql query that must be executed
json ALB_ENGINE::_select(const string& _QUERY)
{
	cout << "query: " << _QUERY << "\n";

	size_t select_word_pos = _QUERY.find("SELECT");
	if (select_word_pos != 0)
	{
		error("No SELECT part!");
		abort();
	}

	vector<vector<string>> result = preg_match_all("(?<!['\"`])FROM(?!['\"`])", _QUERY);
	if (result[0].size() == 0)
	{
		error("No FROM part!");
		abort();
	}
	else if (result[0].size() > 1)
	{
		error("Wrong syntax near FROM part!");
		abort();
	}
	result.clear();

	result = preg_match_all("^SELECT(.*)\\s*?FROM\\s*?", _QUERY);
	//var_dump(result);

	// finding columns name - parsing query until FROM
	for (size_t i = 6; i < _QUERY.size(); i++)
	{
		auto const& _char = _QUERY[i];

		if (true)
		{
		}

		//cout << _char << endl;
	}

	return "[{\"id\": 1,\"username\" : \"michael\",\"password\" : \"delasor\",\"salt1\" : \"\",\"salt2\" : \"\",\"gamedata\" : {}}]"_json;
}

// _table_name   - name of table from which data will be selected
// _all_columns  - if set into true, all columns will be selected, no matter what is passed into _columns_name
// _columns_name - if _all_columns set into false, _columns_name means names of columns which will be selected from _table_name
// _coditions    - first vector means name of columns and second vectors means value for this column. If several conditions are selected
//                 they are merge with operator AND. Leave empty vector for not using
// _order        - first vector means name of columns and second vector means how they must be ordered. Leave empty vector for not using
//                 only one column is allowed
// _limit        - how many records must be selected. -1 means this option turned off
json ALB_ENGINE::_select(string _table_name, bool _all_columns, vector<string> _columns_name, vector<vector<string>> _conditions,
	vector<vector<string>> _order, int _limit)
{
	_table_name = trim(_table_name);

	// IF_TABLE_NAME_ENTERED BEG
	if (_table_name == "")
	{
		error("Table name must be entered!");
		abort();
	}
	// IF_TABLE_NAME_ENTERED END

	// IF_TABLE_EXIST BEG
	if (!ALB_ENGINE::exist_table(_table_name))
	{
		error("Table with name \"" + _table_name + "\" was not found!");
		abort();
	}
	// IF_TABLE_EXIST END

	// CHECKING_CONDITIONS BEG
	json table_data_j = ALB_ENGINE::read_table(_table_name);

	json table_with_conditions = json::parse("[]");
	if (!_conditions.empty())
	{
		if (_conditions.size() != 2)
		{
			error("_conditions is not empty and does not fill the requirments - only two elements in it!");
			abort();
		}

		if (_conditions[0].size() != _conditions[1].size())
		{
			error("_conditions element do not fill the requirment - their size must be same, because first vector"
				"describes names of columns and the second one describes values that will be compared with database's value!");
			abort();
		}

		vector<string> columns_do_not_exist;
		if (!ALB_ENGINE::are_columns_existing_at_table(_table_name, _conditions[0], columns_do_not_exist))
		{
			string errorMsg = "Several columns do not exist at _conditions:\n";
			for (auto val : columns_do_not_exist)
			{
				errorMsg += "\t\"" + val + "\";\n";
			}
			error(errorMsg);
			abort();
		}

		int count_true_where_clause = 0;
		int i = 0;
		for (auto row : table_data_j)
		{
			size_t conditions_count = _conditions[0].size();

			for (size_t i = 0; i < conditions_count; i++)
			{
				if (row[_conditions[conditions_const::COLUMN_NAME][i]] == _conditions[conditions_const::COLUMN_VAL][i])
				{
					count_true_where_clause++;
				}
			}

			if (count_true_where_clause == conditions_count)
			{
				table_with_conditions.push_back(row);

				i++;
			}

			count_true_where_clause = 0;
		}
	}
	else
	{
		table_with_conditions = table_data_j;
	}

	// CHECKING_CONDITIONS END

	// SELECTING_COLUNMS BEG
	json table_with_selected_columns = json::parse("[]");

	if (!_all_columns)
	{
		if (_columns_name.size() == 0)
		{
			error("There is no columns given! Give selected columns names or set _all_columns into true!");
			abort();
		}

		vector<string> columns_do_not_exist;
		if (!ALB_ENGINE::are_columns_existing_at_table(_table_name, _columns_name, columns_do_not_exist))
		{
			string errorMsg = "Several columns do not exist at _columns_name:\n";
			for (auto val : columns_do_not_exist)
			{
				errorMsg += "\t\"" + val + "\";\n";
			}
			error(errorMsg);
			abort();
		}

		int i = 0;
		for (auto row : table_with_conditions)
		{
			table_with_selected_columns.push_back(json::parse("{}"));
			for (auto column_name : _columns_name)
			{
				table_with_selected_columns[i][column_name] = row[column_name];
			}

			i++;
		}
	}
	else
	{
		table_with_selected_columns = table_with_conditions;
	}
	// SELECTING_COLUNMS END

	// ORDER_BY BEG
	json ordered_table = json::parse("[]");
	ordered_table = table_with_selected_columns;

	if (!_order.empty())
	{
		if (_order.size() != 2)
		{
			error("_order is not empty and does not fill the requirments - only two elements in it!");
			abort();
		}

		if (_order[0].size() != _order[1].size())
		{
			error("_order element do not fill the requirment - their size must be same, because first vector"
				"describes names of columns and the second one describes how they must be ordered!");
			abort();
		}

		if (_order[0].size() != 1)
		{
			error("Only by one column result can be ordered!");
			abort();
		}

		vector<string> columns_do_not_exist;
		if (!ALB_ENGINE::are_columns_existing_at_table(_table_name, _order[0], columns_do_not_exist))
		{
			string errorMsg = "Several columns do not exist at _order:\n";
			for (auto val : columns_do_not_exist)
			{
				errorMsg += "\t\"" + val + "\";\n";
			}
			error(errorMsg);
			abort();
		}

		vector<string> order_const = { "ASC", "DESC" };
		if (!in_array(_order[1][0], order_const))
		{
			error("Only ASC and DESC options are allowed!");
			abort();
		}

		int max_element = ordered_table.size() - 1, index;
		json temp;
		while (max_element >= 0)
		{
			index = 0;
			while (index <= max_element - 1)
			{
				if (_order[1][0] == "ASC")
				{
					if (ordered_table[index][_order[0][0]] > ordered_table[index + 1][_order[0][0]])
					{
						temp = ordered_table[index];
						ordered_table[index] = ordered_table[index + 1];
						ordered_table[index + 1] = temp;
					}
				}

				if (_order[1][0] == "DESC")
				{
					if (ordered_table[index][_order[0][0]] < ordered_table[index + 1][_order[0][0]])
					{
						temp = ordered_table[index];
						ordered_table[index] = ordered_table[index + 1];
						ordered_table[index + 1] = temp;
					}
				}

				index += 1;
			}

			max_element = max_element - 1;
		}
	}
	else
	{
		// do nothing
	}
	// ORDER_BY END

	// LIMIT BEG
	json limited_table = json::parse("[]");
	if (_limit >= -1)
	{
		if (_limit > -1)
		{
			int i = 0;
			for (auto elem : ordered_table)
			{
				if (i == _limit)
					break;

				limited_table.push_back(elem);

				i++;
			}
		}
		else
		{
			limited_table = ordered_table;
		}
	}
	else
	{
		error("Limit cannot be negative integer!");
		abort();
	}
	// LIMIT END

	return limited_table;
}

bool ALB_ENGINE::_insert(const string& _QUERY)
{

	return true;
}

bool ALB_ENGINE::_insert(string _table_name, vector<vector<string>> _cols_n_vals)
{
	_table_name = trim(_table_name);

	// IF_TABLE_NAME_ENTERED BEG
	if (_table_name == "")
	{
		error("Table name must be entered!");
		abort();
		//return false;
	}
	// IF_TABLE_NAME_ENTERED END

	// IF_TABLE_EXIST BEG
	if (!ALB_ENGINE::exist_table(_table_name))
	{
		error("Table with name \"" + _table_name + "\" was not found!");
		abort();
		//return false;
	}
	// IF_TABLE_EXIST END

	if (_cols_n_vals.empty())
	{
		error("_cols_n_vals cannot be empty!");
		abort();
		//return false;
	}

	if (_cols_n_vals.size() != 2)
	{
		error("_cols_n_vals must contain only 2 elements!");
		abort();
		//return false;
	}

	if (_cols_n_vals[0].size() != _cols_n_vals[1].size())
	{
		error(
			"_cols_n_vals element do not fill the requirment - elements size must be same, because first vector"
			"describes names of columns and the second one describes values must be inserted!");
		abort();
		//return false;
	}

	if (_cols_n_vals[0].size() == 0)
	{
		error("_cols_n_vals element connot be empty!");
		abort();
		//return false;
	}

	vector<string> columns_do_not_exist;
	if (!ALB_ENGINE::are_columns_existing_at_table(_table_name, _cols_n_vals[0], columns_do_not_exist))
	{
		string errorMsg = "Several columns do not exist at _cols_n_vals:\n";
		for (auto val : columns_do_not_exist)
		{
			errorMsg += "\t\"" + val + "\";\n";
		}
		error(errorMsg);
		abort();
		//return false;
	}

	json _table_config = ALB_ENGINE::get_table_confing_data(_table_name);
	json _table_data = ALB_ENGINE::read_table(_table_name);

	vector<string> default_columns = {};
	string a_i_column = "";
	json column_data;
	const vector<string> all_existing_cols = ALB_ENGINE::get_all_existed_columns_names(_table_name);
	for (const auto& ex_column_name : all_existing_cols)
	{
		if (!in_array(ex_column_name, _cols_n_vals[0]))
		{
			column_data = find_column_config_data(_table_name, ex_column_name);
			if (column_data["default"] == nullptr)
			{
				if (column_data["auto_increment"] == false)
				{
					error(ex_column_name + " column does not have default option! It must be pointed!");
					abort();
					//return false;
				}
				else
				{
					a_i_column = column_data["name"];
				}
			}
			else
			{
				default_columns.push_back(column_data["name"]);
			}
		}
	}

	json data_to_insert;
	for (auto const& column_name : all_existing_cols)
	{
		data_to_insert[column_name] = nullptr;
	}

	if (a_i_column != "")
	{
		int max = get_last_auto_inc_val(_table_name);
		data_to_insert[a_i_column] = max + 1;
	}

	if (!default_columns.empty())
	{
		for (auto const& default_column : default_columns)
		{
			json column_config_data = find_column_config_data(_table_name, default_column);
			auto default_val = column_config_data["default"];

			data_to_insert[default_column] = default_val;
		}
	}

	for (size_t iter = 0; iter < _cols_n_vals[0].size(); iter++)
	{
		data_to_insert[_cols_n_vals[0][iter]] = _cols_n_vals[1][iter];
	}

	ALB_ENGINE::add_row_to_table(_table_name, data_to_insert);

	json _table_config_last = ALB_ENGINE::get_table_confing_data(_table_name);
	_table_config_last["last_auto_inc_val"] = data_to_insert[a_i_column];
	string result = _table_config_last.dump(4);
	writeFile(string(_ALB_DATABASE_ENGINE_FOLDER_NAME_) + "/" + DBName + "/" + _table_name + ".config.json", result);

	return true;
}

bool ALB_ENGINE::_delete(const string& _QUERY)
{

	return true;
}

bool ALB_ENGINE::_update(const string& _QUERY)
{

	return true;
}