## 📘 Student Records Management System (C - Linked List)

This project is a command-line based **Student Records Management System** written in C, using a singly linked list to dynamically manage data. It allows users to add, view, delete, modify, and save student records efficiently.

### 🎮 Menu Options

You can choose operations from the following menu:

```
a/A : Add new record
d/D : Delete a specific record
s/S : Show all records
m/M : Modify existing records
v/V : Save data into file
t/T : Sort the records
l/L : Delete all records
r/R : Reverse the records list
e/E : Exit
k/K : Read data from file
```

## Code Structure
- `header.h`: Contains the structure definition and function prototypes.
- `main.c`: The main program that drives the application.
- `insert.c`: Functions to add new records.
- `delete.c`: Functions to delete records.
- `modify.c`: Functions to modify existing records.
- `print.c`: Functions to display records.
- `file.c`: Functions to save and read records from a file.
- `sort.c`: Functions to sort records.
- `reverse.c`: Functions to reverse the order of records.
- `exit.c`: Functions to handle exiting the program.

### 🧠 Data Structure Used

- **Singly Linked List (SLL)** to manage dynamic student data
- Each student record contains:
  - `rollno` (Integer)
  - `name` (String)
  - `percentage` (Float)

### 🖥️ How to Compile and Run

```bash
gcc main.c delete.c -o student_records
./student_records
```

### 🎯 Usage

This project is ideal for beginners learning:

- Linked lists in C
- File handling
- Command-line interfaces
- Dynamic memory management

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/student-database.git
   cd student-database
   ```

2. Compile the code:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./outfile
   ```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

