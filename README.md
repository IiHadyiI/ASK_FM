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


📈 Future Improvements

    Replace file-based storage with SQLite or JSON-based persistence.

    Implement dependency injection instead of using Singletons for system managers.

    Improve input validation and error handling.

    Enhance data encryption for sensitive user data.
