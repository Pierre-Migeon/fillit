# fillit

A program to assemble tetrominos into the smallest square.

Usage:
```./fillit tertimino_file```

For this program, an input of tetriminoes is given, and the program "fillit" finds a way to arrange them into the smallest possible square. Example tetriminoes can be found in the test_case directory. For this project, I decided to opt for bit-representation of the tetrimino pieces rather than a string representation in order to save computational resources and reduce the operating time of the program. Recursive backtracking was chosen to tackle the problem of finding the smallest possible square. The output retains information about the input order of the tetriminoes by labelling the pieces alphabetically in the output square. 

Examples of tertiminoes are as follows:

	....	....	#...	....
	##..	####	###.	##..
	.#..	....	....	.##.
	.#..	....	....	....

The tetriminoe shape is demarked by a octathorpe, whereas any space not taken up by the tetriminoe within a 4x4 matrix representing the piece is represented by a period. Here is an example of what the output of running the program would look like with these 4 pieces used as input:


![example_output](https://user-images.githubusercontent.com/8321639/71452998-b7096500-274e-11ea-88a5-edead1cb725d.png)



