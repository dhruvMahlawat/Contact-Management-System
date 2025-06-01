# Contact Management System (CMS) - C++

A console-based application to manage contacts efficiently with persistent storage. Features include adding, viewing, searching, editing, and deleting contacts with phone number validation.

## Features

- ✨ **Add Contact**: Create new contacts with validation for 10-digit phone numbers
- 📋 **List Contacts**: View all saved contacts in a formatted list
- 🔍 **Search Contact**: Find contacts by phone number
- ✏️ **Edit Contact**: Modify existing contact details
- 🗑️ **Delete Contact**: Remove contacts by phone number
- ✅ **Phone Validation**: Ensures phone numbers contain only digits
- 💾 **Persistent Storage**: Contacts saved in binary file format
- 🎨 **Colorful Interface**: Visual feedback with colored console output

## Getting Started

### Prerequisites
- C++ compiler (supports C++11 or later)
- Windows OS (uses `conio.h` and `system("cls")`)

### Compilation & Execution
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/contact-management-system.git
   cd contact-management-system
   ```
2. Compile the program:
   ```bash
   g++ main.cpp -o cms
   ```
3. Run the executable:
   ```bash
   ./cms
   ```

### For Linux/macOS Users
Replace Windows-specific functions:
1. Replace `#include <conio.h>` with a compatible alternative (e.g., `ncurses`)
2. Change `system("cls")` to `system("clear")`
3. Modify `getch()` to platform-equivalent input function

## Usage
After launching the program:
1. Use the numeric keys to navigate the menu:
   ```
   [1] Add a new Contact
   [2] List all Contacts
   [3] Search for contact
   [4] Delete a Contact
   [5] Edit a Contact
   [0] Exit
   ```
2. Follow on-screen prompts for each operation
3. Contacts are automatically saved to `CMS.dat`

## File Structure
- `CMS.dat`: Binary storage file for contact records
- `temp.dat`: Temporary file used during contact deletion

## Code Structure
```plaintext
contact-management-system/
├── main.cpp           # Main program implementation
├── CMS.dat            # Contacts database (auto-generated)
└── README.md          # This documentation
```

## Validation Rules
- Phone numbers must:
  - Contain exactly 10 digits
  - Contain only numeric characters (0-9)
  - No spaces or special characters allowed

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request.

## Support
For help or issues, please open a GitHub issue.
