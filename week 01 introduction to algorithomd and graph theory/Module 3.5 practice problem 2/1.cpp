/*
Calculate time and space complexity of the following code snippet:

int a = 0, b = 0;
int matrix[N][M];
for (i = 0; i < N; i++) {
    a = a + i;
    matrix[i][i] = a;
}
for (j = 0; j < M; j++) {
    b = b + 2 * j;
}

Ans
==================
Time Complexity=O(1)+O(n*M)+O(n)=O(n*M)
Space Complexity=O(1)+O(n*M)+O(n)=O(n*M)



*/