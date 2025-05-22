# 🚆 Train Reservation System in C

A console-based **Train Reservation System** implemented in C using a doubly linked list. This system allows users to manage seat reservations, cancel bookings, and display reservations in forward and reverse order.

---

## 💡 Features

- ✅ Add new reservations at specific positions
- ❌ Cancel reservations by Reservation ID
- 🔁 Move reservations to new seat numbers
- 📜 Display all reservations (forward and backward)
- ➗ Split reservations into odd/even seat number lists
- 🔄 Fully menu-driven system for easy interaction

---

## 🛠️ Technologies Used

- **Language**: C
- **Data Structure**: Doubly Linked List
- **Compiler**: GCC / Any C compiler

---

## 📂 File Structure

```bash
train_reservation_system.c   # Main source code file
README.md                    # Project documentation
📸 Sample Functionalities
text
Copy
Edit
Train Reservation System

1. Add Reservation
2. Cancel Reservation
3. Move Reservation
4. Display Reservations Forward
5. Display Reservations Backward
6. Split by Seat Numbers (Odd/Even)
7. Exit
Enter your choice:
📌 How It Works
Each reservation is stored as a node with:

reservation_id

name

seat_number

Doubly linked list allows traversal in both directions.

System handles insertions, deletions, updates, and splits seamlessly.

🚀 How to Run
Compile the program:

bash
Copy
Edit
gcc train_reservation_system.c -o reservation
Run the executable:

bash
Copy
Edit
./reservation
🤝 Contributing
Contributions are welcome! Please fork the repo and submit a pull request.

📄 License
This project is licensed under the MIT License.

🙌 Acknowledgements
Built as part of a C programming learning project involving data structures like linked lists. Great for beginners to understand dynamic memory, pointers, and node operations.

scss
Copy
Edit
