<!DOCTYPE html>
<html>
<head>
    <title>Dictionary Project README</title>
</head>
<body>
    <h1>Dictionary Project</h1>
    <p>This project implements a dictionary data structure using a linked list in C. The dictionary stores key-value pairs, where the keys are integers and the values are also integers.</p>
Copy code<h2>Files</h2>
<ul>
    <li><code>node.h</code> and <code>node.c</code>: Define the Node struct and operations for creating, freeing, and manipulating individual nodes of the linked list.</li>
    <li><code>linkedlist.h</code> and <code>linkedlist.c</code>: Define the LinkedList struct and operations for creating, destroying, and manipulating the linked list.</li>
    <li><code>dictionary.h</code> and <code>dictionary.c</code>: Define the Dictionary struct and operations for creating, destroying, and manipulating the dictionary, which uses the linked list to store key-value pairs.</li>
    <li><code>result.h</code>: Defines an enumeration for possible result codes returned by some functions.</li>
</ul>

<h2>Key Functions</h2>
<ul>
    <li><code>initDictionary()</code>: Initializes a new dictionary by allocating memory for the dictionary and linked list.</li>
    <li><code>destroyDictionary()</code>: Frees the memory used by the dictionary and linked list.</li>
    <li><code>sizeOfDictionary()</code>: Returns the number of key-value pairs in the dictionary.</li>
    <li><code>putInDictionary()</code>: Inserts a new key-value pair into the dictionary, maintaining the sorted order of keys.</li>
    <li><code>getFromDictionary()</code>: Retrieves the value associated with a given key in the dictionary.</li>
    <li><code>removeFromDictionary()</code>: Removes the key-value pair with the given key from the dictionary.</li>
    <li><code>printDictionary()</code>: Prints all key-value pairs in the dictionary.</li>
    <li><code>createDictionaryFromArrays()</code>: Creates a new dictionary and populates it with key-value pairs from given arrays of keys and values.</li>
</ul>

<h2>Usage</h2>
<p>To use the dictionary, include the <code>dictionary.h</code> header file in your C program and call the appropriate functions to create, manipulate, and destroy the dictionary.</p>

<p>Example usage:</p>
<pre><code>#include "dictionary.h"
int main() {
Dictionary* dict = initDictionary();
Copy codeputInDictionary(dict, 1, 10);
putInDictionary(dict, 3, 30);
putInDictionary(dict, 2, 20);

printf("Dictionary size: %d\n", sizeOfDictionary(dict));
printDictionary(dict);

int value = getFromDictionary(dict, 2);
printf("Value for key 2: %d\n", value);

removeFromDictionary(dict, 1);
printDictionary(dict);

destroyDictionary(dict);

return 0;
}
</code></pre>
</body>
</html>
