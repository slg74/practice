def is_digit_power_sum(num, power):
    digit_sum = sum(int(d)**power for d in str(num))
    return digit_sum == num

# Upper bound: 9^5 * 6 = 354294 (6 digits is max possible)
result = []
for num in range(2, 354294):
    if is_digit_power_sum(num, 5):
        result.append(num)

total = sum(result)
print(total)
