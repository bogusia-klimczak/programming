from random import randint


def main_menu():
    print("------------------")
    print("MAIN MENU")
    print("------------------")
    print("Press:")
    print("------------------")
    print("1 - to generate list of random elements")
    print("2 - to generate list and fill it with elements")
    print("3 - to get statistics about list")
    print("4 - to show list")
    print("e - to end the program")
    print("------------------")


def generate_random_list():
    n = input("Enter number of elements: ")
    a = input("Min limit of range: ")
    b = input("Max limit of range: ")

    n = int(n)
    a = int(a)
    b = int(b)

    i = 0
    m_list = []
    while i < n:
        rand_num = randint(a, b)
        m_list.append(rand_num)
        i += 1

    return m_list


def generate_fill_list():
    n = input("Enter number of elements: ")

    n = int(n)

    i = 0
    m_list = []
    while i < n:
        rand_num = input((i + 1) + ") Enter number: ")

        rand_num = int(rand_num)

        m_list.append(rand_num)
        i += 1

    return m_list


def get_average(m_list):
    sum = 0
    for elem in m_list:
        sum += elem

    return (sum / len(m_list))


def get_mediana(m_list):
    l_len = len(m_list)

    m_list.sort()

    if l_len % 2 == 1:
        res = m_list[int(len(m_list) / 2 - 0.5)]
    else:
        a = m_list[int(len(m_list) / 2 - 1)]
        b = m_list[int(len(m_list) / 2)]

        res = (a + b) / 2

    return res


key = ""
_list = []

while True:
    main_menu()

    key = input("> ")

    key.lower()
    key.strip()

    if key == "e":
        print("You've chosen to exit. Bye")
        break
    elif key == "1":
        print("Generate random list")

        _list = generate_random_list()
    elif key == "2":
        print("Fill list")

        _list = generate_fill_list()
    elif key == "3":
        print("Show Statistics")

        print("Average value: " + str(get_average(_list)))
        print("Mediana: " + str(get_mediana(_list)))
        print("Min value: " + str(min(_list)))
        print("Max value: " + str(max(_list)))
    elif key == "4":
        print("Show List")

        print(_list)
    else:
        print("Unknown option")
