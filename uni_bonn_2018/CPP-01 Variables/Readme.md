# Variables

## Declaring variables

`<TYPE> <NAME> [=<VALUE>]`

- Every variable has a type and it can't be changed.
- **Always initialize** variables if you can

## Naming variables

- Name **must** start with a letter
- Give variables **meaningful names**
- Don't include type and use negation in the name
- `GOOGLE-STYLE` name variables in `snake_name`- all lower with underscores
- **C++ is case sensitive**

## Built-in types

```
bool this_is_fun = false;  // Boolean: true or false.
char carret_return = '\n'; // Single character.
int meaning_of_life = 42;  // Integer number.
short smaller_int = 42;    // Short number.
long bigger_int = 42;      // Long number.
float fraction = 0.01f;    // Single precision float.
double precise_num = 0.01; // Double precision float.
auto some_int = 13;        // Automatic type [int].
auto some_float = 13.0f;   // Automatic type [float].
auto some_double = 13.0;   // Automatic type [double].
```

For more details, https://en.cppreference.com/w/cpp/language/types

## Constant

- use `const` to declare a constant. Use `CamelCase` to write the name.
- `const` is part of type. Ex. `kSomeInt` has type `const int`

```
const int kSomeInt = 20;
```

## Operations

### Arithmetic types

- All **character**, **integer** and **floating point**.
- Operations: `+`, `-`, `*`, `/`
- Comparisons: `<`, `>`, `<=`, `>=`, `==` return `bool`
- `a += 1` <=> `a = a + 1`
- Avoid `==` for floating point types. Specific to c++

### Additional operations

- Boolean variables: or-> `||`, and-> `&&`, not-> `!`
- Integers
  - `/` is integer division: i.e `7 / 3 == 2`. Use `.` like `7.0 / 3.0`. Types are converted to the biggest one like `7.0 / 3`-> Every variable is converted to float here.
  - `%` modulo division: i.e `7 % 3 == 1`
  - Increment => `a++`
  - Decrement => `a--`
  - Do not use de- increment operators within another expression, i.e `a = (a++) + ++b`. Here, a will first return value the update wheras b will first update and then returns value

## Strings

- `#include <string>` to use `std::string`
- Concat- `+`
- Check if `str` is empty with `str.empty()`
- Works out of the box with I/O streams

```
#include <iostream >
#include <string >
int main() {
    std::string hello = "Hello";
    std::cout << "Type your name:" << std::endl;
    std::string name = ""; // Init empty.
    std::cin >> name; // Read name.
    std::cout << hello + ", " + name + "!" << std::endl;
    return 0;
}
```

## Collection of items

- `#include <array>` to use `std::array`
- Store a collection of items of same type

```
array<float, 3> arr = {1.0f, 2.0f, 3.0f} // <type, size>
```

- Access `arr[i]`, starts with `0`
- Number of items: `arr.size()`
- Aliases
  - First item: `arr.front()` == `arr[0]`
  - Last item: `arr.back()` == `arr[arr.size()-1]`

## Vectors

When number of items is unknown before-wise

- `#include <vector>` to use `std::vector`
- Vector is implemented as a `dynamic table`
- Add a new item
  - `vec.emplace_back(value)` [preferred, c++11]
  - `vec.push_back(value)` [historically known]

**Optimize vector resizing**

- Many `push_back` opertaions force vector to change its size many times. Use `reserve(n)` which ensures that the vector has enough memory to store `n` items. Think like you have to start with empty vector and keep adding all numbers one by one.

```
# Sample code for vector push_back, front and back
c++ -std=c++11 -o vector1.out vector1.cpp
./vector1.out

# OUTPUT
Len of vector:2
Front element:1
Back element:2
Pushing back an integer 10
Len of vector:3
Back element:10
Pushing back an double 3.2
Back element:3
```

## References

- Use `&` to state that a variable is a reference. It is part of type. Here, `ref` has type `float&`

```
float& ref = original_variable;
```

- Whatever to reference happens to the variable and vice versa. **Yields performance gain as references avoid copying data**

```
# Sample code for refernece
c++ -std=c++11 -o reference1.out reference1.cpp
./reference1.out
```

- **Const with references** - References are fast but reduce control. Use `const`

```
const float& ref = original_variable;
const std::string& hello_ref = hello;
```

# Control structures

## If else

```
if(statement){

}else if (statement2){

}else{

}
```

## Switch

- Difference is that the `statement` does not need to evaluate to bool, could int like thing
- A case can have constants not variable expression. Use `break` to stop across multiple case.
- If not case matches, the `default` will execute.
- Useful for fixed options from a set of options.

```
switch(STATEMENT){
  case CONST_1:
  case CONST_2:
    break;
  default:
}
```

## Loops

### While loop

```
while(STATEMENT){

}
```

- Used when the number of iterations are unknown

### For loop

- In C++ `for` loops are very fast
- Less flexible than while but less error-prone

```
for(INTIAL_CONDITION; END_CONDITION; INCREMENT){
  // Until END_CONDITION == false
}

for (int i = 0; i<COUNT; ++i){

}
```

```
# Sample code for for_loop
c++ -std=c++11 -o for_loop1.out for_loop1.cpp
./for_loop1.out
```

#### Range for loop

- Iterating over standard containers like `arrays` and `vectors`.
- Use it when need to iterate over all elements.

```
# Sample code for range for loop- vector, string and strings
c++ -std=c++11 -o for_loop2.out for_loop2.cpp
./for_loop2.out
```

### Exit loops and iterations

- break
- continue
