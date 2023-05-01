/*
Calculate time and space complexity of the following code:

int a = 0;
for (i = 0; i < N; i++) {
    for (j = N; j > i; j--) {
        a = a + i + j;
    }
}

Time complexity is=O(1)+O(n^2)=O(n^2)
Space complexity is =O(1);


*/