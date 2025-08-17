# C++ Exercises Collection

A small collection of C++ console programs covering input handling, validation,
loops, file I/O, and simple menu-driven apps.

## Files

- **input_name_and_code_validation.cpp**  
  Two small examples aimed at reading a user name and a numeric code with validation.  

- **count_to_n.cpp**  
  Reads an integer `n` and prints `1 2 3 ... n`.  

- **bmi_calculator_with_menu.cpp**  
  Menu-based BMI tool: captures patient ID and name, records height and weight,
  calculates BMI with `setprecision`, and prints a formatted report.  

- **pharmacy_recipes_and_inventory_cli.cpp**  
  CLI to register products (append to `MEDICAMENTOS.txt`), add keyword
  associations (`CLAVES.txt`), validate indications, and register prescriptions
  (`RECETA.txt`).  

- **annual_bonus_calculator.cpp**  
  Prompts for 12 monthly salaries and computes the annual bonus (aguinaldo)
  as `sum / 12`.  


## Build

All examples are standard C++ (C++17 is fine). Compile each independently:

```bash
# Linux / macOS (g++)
g++ -std=c++17 -Wall -Wextra -O2 -o count_to_n count_to_n.cpp
g++ -std=c++17 -Wall -Wextra -O2 -o bmi_calculator_with_menu bmi_calculator_with_menu.cpp
g++ -std=c++17 -Wall -Wextra -O2 -o pharmacy_cli pharmacy_recipes_and_inventory_cli.cpp
g++ -std=c++17 -Wall -Wextra -O2 -o annual_bonus_calculator annual_bonus_calculator.cpp
g++ -std=c++17 -Wall -Wextra -O2 -o prompt_user_name prompt_user_name.cpp
g++ -std=c++17 -Wall -Wextra -O2 -o prompt_user_code_int prompt_user_code_int.cpp
g++ -std=c++17 -Wall -Wextra -O2 -o input_validation input_name_and_code_validation.cpp
