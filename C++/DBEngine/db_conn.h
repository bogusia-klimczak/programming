#pragma once

#ifndef _DB_CONN_H_
#define _DB_CONN_H_

// INCLUDE BLOCK BEG
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
// INCLUDE BLOCK END

// NAMESPACE BLOCK BEG
using nlohmann::json;
using std::string;
using std::vector;
// NAMESPACE BLOCK END

// DEFINE BLOCK BEG
#define error(x) cout << "Error:\n" << __FILE__ << ":" << __LINE__ << ":\n" << x
#define P(x) cout << __LINE__ << " - " << #x << ": " << x << endl
#define _ALB_DATABASE_ENGINE_FOLDER_NAME_ "ALB_DATABASE_ENGINE"
// DEFINE BLOCK END

namespace albdarion
{
	class ALB_ENGINE
	{
	private:
		int DBUserID;
		string DBUserName;
		string DBUserPassword;
		string DBName;
		json DBData;

		enum conditions_const
		{
			COLUMN_NAME = 0,
			COLUMN_VAL = 1
		};

		// default constructor
		ALB_ENGINE();

		// function that initiate database data into DBData
		void initiate_database_data();

		// checks is there a table with name _table_name at DBName database
		bool exist_table(string _table_name);

		// reads and returns data of table with name _table_name as json
		json read_table(string _table_name);

		// returns table configuration data such as information about columns (type, default value etc.)
		json get_table_confing_data(string _table_name);

		// returns all existing columns names in table _table_name
		vector<string> get_all_existed_columns_names(string _table_name);

		bool are_columns_existing_at_table(string _table_name, vector<string> _columns_names, vector<string>& _columns_do_not_exist);

		vector<string> find_auto_inc_col_in_table(string _table_name);

		json find_column_config_data(string _table_name, string _column_name);

		int get_last_auto_inc_val(string _table_name);

		bool add_row_to_table(string _table_name, json row);

	public:
		// _DBName     - database name
		// _DBUsername - username of user to connect to database
		// _DBPassword - password to connect to database
		ALB_ENGINE(string _DBName, string _DBUsername, string _DBPassword);

		~ALB_ENGINE() {};

		// _QUERY - sql query that must be executed
		json _select(const string& _QUERY);

		// _table_name   - name of table from which data will be selected
		// _all_columns  - if set into true, all columns will be selected, no matter what is passed into _columns_name
		// _columns_name - if _all_columns set into false, _columns_name means names of columns which will be selected from _table_name
		// _coditions    - first vector means name of columns and second vectors means value for this column. If several conditions are selected
		//                 they are merge with operator AND. Leave empty vector for not using
		// _order        - first vector means name of columns and second vector means how they must be ordered. Leave empty vector for not using
		//                 only one column is allowed
		// _limit        - how many records must be selected. -1 means this option turned off
		json _select(string _table_name, bool _all_columns, vector<string> _columns_name, vector<vector<string>> _conditions = {},
			vector<vector<string>> _order = {}, int _limit = -1);

		bool _insert(const string& _QUERY);

		bool _insert(string _table_name, vector<vector<string>> _cols_n_vals);

		bool _delete(const string& _QUERY);

		bool _update(const string& _QUERY);
	};
} // namespace albdarion

#endif // _DB_CONN_H_