# Sanidhya_Hari_Rastogi_Impledge_Assignment
### Word Composition Problem

### Overview
This program aims to solve the Word Composition Problem by identifying the longest and second longest compounded words in a given list. A compounded word is one that can be constructed by concatenating shorter words from the same list. The solution utilizes a Trie data structure for efficient word search and processing.

### Implementation Details

- The program first reads the contents of the provided files and stores each line as an element in a vector.
- It utilizes a Trie data structure with nodes having children arrays and an `isEnd` flag to mark the end of a word.
- The program inserts the words from the input files into the Trie and searches for compound words using a recursive approach.
- It tracks the time taken for processing the input files using the `chrono` library and prints the duration in seconds.

### Design Decisions and Approach

The Trie data structure was chosen for its efficiency in word insertion and search operations. The program iteratively processes the word list, updating the Trie and identifying compounded words. The recursive function plays a crucial role in traversing the Trie and determining the compound nature of a given word. This design ensures optimal performance even for large lists.

### Running the Program

To run the program, provide the input files `input_01.txt` and `input_02.txt`. The program will display the longest compound word and the second longest compound word from each file along with the time taken to process each file.

Feel free to modify the program to process multiple input files by extending the logic in the `main` function.

### Performance
The program exhibits excellent space and time efficiency:
Space Complexity: O(N) - Influenced by the Trie structure storing each character in each word.
Time Complexity: O(W * M) - Primarily determined by Trie operations during insertion, search, and recursive checks. Despite this worst-case scenario, the Trie structure ensures efficient searches, enabling high performance even with large lists.

 Reqirements : Ensure you have a compatible C++ compiler installed to execute the program.
