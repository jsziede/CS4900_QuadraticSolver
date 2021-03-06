/**
 * CS 4900
 * Stdin spike.
 */


/**
 * Description:
 *  Spike to test basic stdin handling.
 */


// Import headers.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


// Method Declaration.



/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
    int run_program_bool = 1;
    int index;
    char* input_buffer;     // Buffer to hold user input.
    char* buffer_position;  // Position in input buffer.
    char* input_string;     // Instance of a full line of user input.
    off_t read_value;       // Number of characters initially read in.

    while (run_program_bool) {
        input_buffer = calloc(1, 1024);

        // Read input from console.
        // Uses buffer in case multiple lines are read in at once.
        write(1, "Enter input: ", 14);
        read_value = read(0, input_buffer, 1024);
        if (read_value < 0) {
            fprintf(stderr, "Failed to read line.\n");
        }

        // Iterate through buffer of input, until null terminator (\0) is found.
        // For each end of line (\n), pause read in and handle current input.
        buffer_position = input_buffer;
        while (*buffer_position != '\0') {
            index = 0;
            input_string = calloc(1, 1024);

            // Parse until end of line found.
            while (*buffer_position != '\n') {
                input_string[index] = *buffer_position;
                ++buffer_position;
                index++;
            }
            ++buffer_position;

            printf("Input: %s\n", input_string);
            if (strcmp(input_string, "exit") == 0) {
                run_program_bool = 0;
            }

            free(input_string);
        }
        free(input_buffer);
    }

    exit(0);
}
