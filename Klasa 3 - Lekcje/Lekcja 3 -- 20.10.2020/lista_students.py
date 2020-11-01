import pickle


class Student:
    def __init__(self, name, surname, index_number, rating_list=[]):
        self.__name = name
        self.__surname = surname
        self.__index_number = index_number
        self.__rating_list = rating_list[:]

    def show(self):
        print(f"\tStudent: {self.__name} {self.__surname}")
        print(f"\tIndex Number: {self.__index_number}")
        print(f"\tRating list: {self.__rating_list}")

    def get_name(self):
        return self.__name

    def get_surname(self):
        return self.__surname

    def get_index_number(self):
        return self.__index_number

    def get_rating_list(self):
        return self.__rating_list

    def set_name(self, name):
        self.__name = name

    def set_surname(self, surname):
        self.__surname = surname

    def set_index_number(self, index_number):
        self.__index_number = index_number

    def push_mark(self, mark):
        self.__rating_list.append(mark)

    def pop_mark(self):
        mark = self.__rating_list.pop()
        return mark

    def sort_list_of_marks(self):
        self.__rating_list.sort()

    def avg_rating(self):
        return sum(self.__rating_list) / len(self.__rating_list)


def defense_int_input(text, min_val, max_val):
    value = input(text)
    while (int(min_val) > int(value)) or (int(value) > int(max_val)):
        print('Value should not be less than', min_val, 'and not greater than', max_val, sep=' ', end='\n')
        value = input(text)

    return int(value)


def display_menu():
    print('\nMenu:')
    print('1 - Show all students')
    print('2 - Edit students')
    print('3 - Show selected students')
    print('4 - Read student\'s list from file')
    print('5 - Write student\'s list to the file')
    print('6 - End of program')
    print('\n')
    menu_selection = defense_int_input("Wybierz operacje: ", 1, 6)
    print()

    return menu_selection


def load():
    try:
        with open("bin.dat", "rb") as f:
            students_list = pickle.load(f)
            return students_list

    except Exception:
        pass


def save(students_list):
    with open("bin.dat", "wb") as f:
        pickle.dump(students_list, f)


print('List of students.')
amount_of_students = 0
students_list = []

# student1 = Student("Rafał", "Nowak", 123456, [1, 2, 3, 4, 5])
# student2 = Student("Jan", "Kowalski", 234567, [2, 3, 4, 5])
# student3 = Student("Hanna", "Szymańska", 345678, [3, 4, 5])
# student4 = Student("Maja", "Jankowska", 456789, [4, 5])
#
# students_list.append(student1)
# students_list.append(student2)
# students_list.append(student3)
# students_list.append(student4)
#
# save(students_list)


with open("bin.dat", "rb") as f:
    s_l = pickle.load(f)
    print(f"s_l: {s_l}")
    for s in s_l:
        s.show()

menu_selection = display_menu()

while menu_selection < 6:
    if menu_selection == 1:
        print('List of students:')
        for student in students_list:
            student.show()
            print()
    elif menu_selection == 2:
        if amount_of_students == 0:
            print('To edit student\'s list you have to have at least one student. Fill the list and try again')
        else:
            exit_key = False
            while True:
                id = input('Enter student\'s index number to edit it or "<exit>" to exit edit mode: ')

                if id == '<exit>':
                    exit_key = True
                    break

                if not id.isnumeric():
                    print('Incorrect index number. Try again')
                    continue

                id_int = int(id)

                break_key = False

                for student in students_list:
                    if id_int == student.get_index_number():
                        break_key = True
                        break

                if break_key:
                    break

                print('Student with this index number was not found. Try again')

            if not exit_key:
                print('Student was found\n')
                while True:
                    print('1 - change name')
                    print('2 - change surname')
                    print('3 - change index number')
                    print('4 - push mark')
                    print('5 - pop mark')
                    print('6 - sort list of marks')
                    print('7 - exit edit mode')
                    print('\n')
                    student_edit_option = input('Enter option what you want to change: ')
                    print()

                    if not student_edit_option.isnumeric():
                        print('Incorrect option key. Try again')
                        continue

                    int_student_edit_option = int(student_edit_option)

                    if int_student_edit_option < 1 or int_student_edit_option > 7:
                        print('Wrong option key. Try again')
                        continue

                    if int_student_edit_option == 1:
                        while True:
                            print('Currently name is: ' + student.get_name())
                            name = input('Enter new name or "<exit>" to exit edit name mode: ')

                            if name == '<exit>':
                                break

                            if not name.isalpha():
                                print('Wrong new name for student. Try again')
                            else:
                                student.set_name(name)
                                break
                    elif int_student_edit_option == 2:
                        while True:
                            print('Currently surname is: ' + student.get_surname())
                            surname = input('Enter new name or "<exit>" to exit edit surname mode: ')

                            if surname == '<exit>':
                                break

                            if not surname.isalpha():
                                print('Wrong new surname for student. Try again')
                            else:
                                student.set_surname(surname)
                                break
                    elif int_student_edit_option == 3:
                        while True:
                            print('Currently index number is: ' + str(student.get_index_number()))
                            index_number = input('Enter new index number or "<exit>" to exit edit index_number mode: ')

                            if index_number == '<exit>':
                                break

                            if not index_number.isnumeric():
                                print('Wrong new name for student. Try again')
                            else:
                                int_index_number = int(index_number)
                                exist_key = False
                                for local_loop_student in students_list:
                                    if local_loop_student.get_index_number() == int_index_number:
                                        print('Student with such index number already exists. Try again')
                                        exist_key = True
                                        break

                                if not exist_key:
                                    student.set_index_number(int_index_number)
                                    break
                    elif int_student_edit_option == 4:
                        print('Current list of marks: ', student.get_rating_list())
                        value_of_mark = input('Write value of mark which will be added: ')

                        if not value_of_mark.isnumeric():
                            print('Incorrect value. Returning to edit menu.....')
                        else:
                            int_value_of_mark = int(value_of_mark)
                            student.push_mark(int_value_of_mark)
                            print('After edition: ', student.get_rating_list())
                    elif int_student_edit_option == 5:
                        print('Current list of marks: ', student.get_rating_list())
                        print('Returned value: ' + str(student.pop_mark()))
                        print('After edition: ', student.get_rating_list())
                    elif int_student_edit_option == 6:
                        print('Current list of marks: ', student.get_rating_list())
                        student.sort_list_of_marks()
                        print('After edition: ', student.get_rating_list())
                    elif int_student_edit_option == 7:
                        break
    elif menu_selection == 3:
        print('\n1 - students with average marks greater than X')
        print('2 - students with average marks less than X')
        print('3 - students that got at least one X mark')
        print('\n')
        filter_selection_key = input('Select filter or enter "<exit>" to exit filter mode: ')
        print()

        if not filter_selection_key == "<exit>":
            if not filter_selection_key.isnumeric():
                print('Incorrect filter selection key. Returning to main menu...')
            else:
                int_filter_selection_key = int(filter_selection_key)

                X = input('Enter X value: ')

                if not X.isnumeric():
                    print('Incorrect X value. Returning to main menu.....')
                else:
                    int_X = int(X)

                    if int_filter_selection_key == 1:
                        for local_loop_student in students_list:
                            if local_loop_student.avg_rating() > int_X:
                                local_loop_student.show()
                    elif int_filter_selection_key == 2:
                        for local_loop_student in students_list:
                            if local_loop_student.avg_rating() < int_X:
                                local_loop_student.show()
                    elif int_filter_selection_key == 3:
                        for local_loop_student in students_list:
                            if int_X in local_loop_student.get_rating_list():
                                local_loop_student.show()
    elif menu_selection == 4:
        students_list = load()
        amount_of_students = len(students_list)
    elif menu_selection == 5:
        save(students_list)
        print('Saved to the file.')

    menu_selection = display_menu()
