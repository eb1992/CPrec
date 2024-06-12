# CPrec Description
A simple command-line tool that lists C operators based on the provided input. The program accepts a list of operator symbols as command-line arguments, sorts them by precedence, and outputs them back along with description, \(P\)recedence and \(A\)ssociativity. 

## Installation (Linux)

To compile and run the program:

1. **Compile the program:**

    ```sh
    gcc -o cprec -O3 cprec.c
    ```

2. **Find directories on PATH**

    ```sh
    echo $PATH
    ```

3. **Move executable to a directory on PATH**
    ```sh
    mv cprec /usr/local/bin

    ```
    Any other directory on PATH is valid here:

    ```sh
    mv cprec </any/directory/on/PATH/bin>
    ```

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

