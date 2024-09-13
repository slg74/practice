
def tuple_elementwise_sum(tuple1, tuple2):
    if len(tuple1) != len(tuple2):
        raise ValueError("Input tuples must have the same length.")
 
    return tuple(a + b for a, b in zip(tuple1, tuple2))



def get_diagonal(tup):
    i=0
    j=0
    result = ()
    
    while i<=2 and j<=2:
        result[i][j] = tup[i][j]
        i += 1 
        j += 1  
        
    return result

input_tuple = (
    (1, 2, 3),
    (4, 5, 6),
    (7, 8, 9)
)
output_tuple = get_diagonal(input_tuple)
print(output_tuple) 