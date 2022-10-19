# TO DO LIST

1. Generate 10000, 100000, and 1 million (1,000,000) random integer numbers
   (ranging from 0 to 9999) for running the sorting.
2. The number of compute nodes (MPI) or the number of threads (OpenMP) is
   varied from 1, 4, 8, 12 and 16. Also, measure the execution time for each data
   group and for each number of compute nodes. Put the results into a table and also
   plot one graph having all results.
3. If the number on each node is below a threshold, say 1000, you can call another
   sorting function to sort those numbers locally

# How to Run quicksort.c

1. command to compile:
   '''
   mpicc -o quicksort quicksort.c -std=c99
   '''
2. command to run:
   '''
   mpirun -np <num_process> ./quicksort <input_filename> <output_filename>
   '''
   Example:
   '''
   mpirun -np 4 ./quicksort input.txt output.txt
   '''
3. It will use the numbers in input file, and put the sorted result in the output file (generated if not exists)
