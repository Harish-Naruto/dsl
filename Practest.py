def print_matrix(matrix):
    for row in matrix:
        print([round(num, 2) for num in row])
    print()

def addition(matrix1,matrix2):
    result = []
    if(len(matrix1)!=len(matrix2) or len(matrix1[0])!=len(matrix2[0])):
        print("Error: matrix should have same dimension")
        return None
    for i in range(len(matrix1)):
        row =[]
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j]+matrix2[i][j])
        result.append(row)
    return result

def substraction(matrix1,matrix2):
    result = []
    if len(matrix1)!=len(matrix2) or len(matrix1[0])!=len(matrix2[0]):
        print("Error: matrix should have same dimension")
        return None
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j]-matrix2[i][j])
        result.append(row)
    return result

def matrix_multiplication(matrix1, matrix2):
 
    if len(matrix1[0]) != len(matrix2):
        print("Error: Number of columns in first matrix must equal number of rows in second matrix")
        return None
    
    rows = len(matrix1)
    cols = len(matrix2[0])
    result = [[0 for _ in range(cols)] for _ in range(rows)]
    
    for i in range(rows):
        for j in range(cols):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    
    return result

def matrix_transpose(matrix):
    
    rows = len(matrix)
    cols = len(matrix[0])
    
    result = []
    for i in range(cols):
        new_row = []
        for j in range(rows):
            new_row.append(matrix[j][i])
        result.append(new_row)
    
    return result
    
matrix1 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    
matrix2 = [
        [9, 8, 7],
        [6, 5, 4],
        [3, 2, 1]
    ]
    
    # Testing all operations
print("Matrix 1:")
print_matrix(matrix1)
    
print("Matrix 2:")
print_matrix(matrix2)
    
print("Addition Result:")
result = addition(matrix1, matrix2)
if result:
    print_matrix(result)
    
print("Subtraction Result:")
result = substraction(matrix1, matrix2)
if result:
    print_matrix(result)
    
print("Multiplication Result:")
result = matrix_multiplication(matrix1, matrix2)
if result:
    print_matrix(result)
    
print("Transpose of Matrix 1:")
result = matrix_transpose(matrix1)
print_matrix(result)