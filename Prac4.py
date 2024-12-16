def print_matrix(matrix):
    """
    Helper function to print a matrix in a readable format
    """
    for row in matrix:
        print([round(num, 2) for num in row])
    print()

def matrix_addition(matrix1, matrix2):
    """
    Adds two matrices of the same dimensions
    Returns None if dimensions don't match
    """
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        print("Error: Matrices must have the same dimensions for addition")
        return None
    
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

def matrix_subtraction(matrix1, matrix2):
    """
    Subtracts matrix2 from matrix1
    Returns None if dimensions don't match
    """
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        print("Error: Matrices must have the same dimensions for subtraction")
        return None
    
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result

def matrix_multiplication(matrix1, matrix2):
    """
    Multiplies two matrices
    Returns None if dimensions are incompatible
    """
    if len(matrix1[0]) != len(matrix2):
        print("Error: Number of columns in first matrix must equal number of rows in second matrix")
        return None
    
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            element = sum(matrix1[i][k] * matrix2[k][j] for k in range(len(matrix2)))
            row.append(element)
        result.append(row)
    return result

def matrix_transpose(matrix):
    """
    Returns the transpose of a matrix
    """
    return [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]

# Example usage
if __name__ == "__main__":
    # Example matrices
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
    result = matrix_addition(matrix1, matrix2)
    if result:
        print_matrix(result)
    
    print("Subtraction Result:")
    result = matrix_subtraction(matrix1, matrix2)
    if result:
        print_matrix(result)
    
    print("Multiplication Result:")
    result = matrix_multiplication(matrix1, matrix2)
    if result:
        print_matrix(result)
    
    print("Transpose of Matrix 1:")
    result = matrix_transpose(matrix1)
    print_matrix(result)