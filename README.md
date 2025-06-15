📌 Ask.fm-Style Q&A Console System (C++)

A console-based social Q&A platform inspired by Ask.fm, built using C++. This system allows users to create accounts, ask and answer questions (both public and anonymous), manage threaded question chains, and delete questions. All data is persisted via text files to simulate lightweight backend storage without a database.
📖 Features

    ✅ User account creation and login system.

    ✅ Ask and answer questions with optional anonymity.

    ✅ Support for threaded questions (users can reply to existing questions).

    ✅ File-based persistence for users, questions, answers, and deletions.

    ✅ Menu-driven command-line interface for easy interaction.

    ✅ Singleton Pattern for centralized system controllers (Ask_sys, Create_User).

    ✅ Simple data reload mechanism to sync files and in-memory data.

🛠️ Technologies & Concepts

    C++17

    Object-Oriented Programming (OOP)

    Singleton Design Pattern

    File I/O for Data Persistence

    Console-based UI

    Basic Software Architecture & Separation of Concerns

📦 Project Structure

project/
├── projectFiles/
│   ├── Questions/
│   │   ├── questions/
│   │   │   ├── questions.txt
│   │   │   └── deleted.txt
│   │   └── answers/
│       └── answers.txt
├── Ask_sys.cpp
├── Create_User.h
├── System_reload.cpp
├── User.cpp
├── Question.h
└── main.cpp

🚀 Getting Started

    Clone the repository

git clone https://github.com/yourusername/askfm-clone.git
cd askfm-clone

Compile the project

g++ -std=c++17 -o askfm main.cpp Ask_sys.cpp User.cpp System_reload.cpp

Run the program

    ./askfm

📈 Future Improvements

    Replace file-based storage with SQLite or JSON-based persistence.

    Implement dependency injection instead of using Singletons for system managers.

    Improve input validation and error handling.

    Add a GUI or web-based frontend using a modern framework.

    Enhance data encryption for sensitive user data.
