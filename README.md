# CPrec Description
A simple command-line tool that lists C operators based on the provided input. The program accepts a list of operator symbols as command-line arguments, sorts them by precedence, and outputs them back along with description, \(P\)recedence and \(A\)ssociativity. 

## Installation

#### Linux

1. **Install the program**
    ```sh
    make install-linux
    ```
This compiles the program at moves it to `$HOME/.local/bin/`. Make sure this directory is on your `$PATH`, otherwise move the executable to a directory on your `$PATH`.

#### Non Linux

1. **Compile the program:**
    ```sh
    make
    ```

2. **Move the executable:**

Move the executable to a directory it can be run from.

## Usage
```sh
  cprec [operator1] [operator2] ... [operatorN]
```

## Example usage

- The input:

    ```sh
    cprec "++" "*" 
    ```

- Gives the output:

    ```
    High.                           P:   A:
    ++       Postfix increment      2    L-T-R
    ++       Prefix increment       3    R-T-L
    *        Dereference            3    R-T-L
    *        Multiplication         3    R-T-L
    Low.
    ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
