import os
from tkinter import Menu

class library:
    def __init__(self, list, name):
        self.booklist = list
        self.name = name
        self.lendDict = {}

    def loginpage(self):
        os.system('cls')
        print("Welcome to the library")
        print("Enter your choice to continue")
        print("1. Login")
        print("2. Register")
        print("3. Exit")
        choice = int(input())
        if choice == 1:
            os.system('cls')

            self.login()
        elif choice == 2:
            os.system('cls')

            self.register()
        elif choice == 3:
            exit()

        else:
            print("Not a valid option")
            input("Press enter to continue")
            self.loginpage()

    def login(self):
        print("Enter your name: ")
        name = input()
        print("Enter your password: ")
        password = input()
        self.name = name
        self.menu()


    
    def register(self):
        print("Enter your name: ")
        name = input()
        print("Enter your password: ")
        password = input()
        print("Enter your email: ")
        email = input()
        print("Enter your phone number: ")
        phone = input()
        print("Enter your address: ")
        address = input()
        print("Enter your age: ")
        age = input()

        print("Registration Successful")
        input("Press enter to continue")
        self.loginpage()

    def menu(self):
        os.system('cls')

        print(f"Welcome to the library {self.name}")

        print("Enter your choice to continue")
        print("1. Display Books")
        print("2. Lend a Book")
        print("3. Add a Book")
        print("4. Return a Book")
        print("5. Exit")
        choice = int(input())
        if choice == 1:
            os.system('cls')

            self.displayBook()
        elif choice == 2:
            os.system('cls')

            book = input("Enter the name of the book you want to lend: ")

            if book not in self.booklist:
                print("Book not found")
                input("Press enter to continue")
                self.menu()
            else:
                user = self.name
                self.lendBook(user, book)

        elif choice == 3:
            os.system('cls')

            book = input("Enter the name of the book you want to add: ")
            self.addBook(book)
        elif choice == 4:
            os.system('cls')

            book = input("Enter the name of the book you want to return: ")
            self.returnBook(book)
        elif choice == 5:
            exit()
        else:
            print("Not a valid option")
            input("Press enter to continue")
            self.menu()

    def addBook(self, book):
        self.booklist.append(book)
        print("Book has been added to the book list")

        input("Press enter to continue")
        self.menu()

    def displayBook(self):
        print(f"We have following books in our library {self.name} :")
        for book in self.booklist:
            print(book)
        
        input("Press enter to continue")
        self.menu()

    def lendBook(self, user, book):
        if book not in self.lendDict.keys():
            self.lendDict.update({book: user})
            print("Lender-Book database has been updated. You can take the book now")
        else:
            print(f"Book is already being used by {self.lendDict[book]}")

        input("Press enter to continue")
        self.menu()

        

    def returnBook(self, book):
        self.lendDict.pop(book)
        print("Book has been returned")

        input("Press enter to continue")
        self.menu()

if __name__ == "__main__":
    list = ['Python', 'C++', 'Java', 'C', 'C#', 'Ruby']
    name = ''
    lib = library(list, name)

    
    lib.loginpage()