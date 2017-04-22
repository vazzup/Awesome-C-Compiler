def main():
	print('Enter the expression')
	expr = input().strip()
	expr = list(expr)
	temp = []
	for j in expr:
		if not j.isspace():
			temp.append(j)
	expr = temp
	expr = ['('] + expr + [')']
	stack_depth = []
	current_depth = 0
	max_depth = 0
	for i in expr:
		if i is '(':
			current_depth += 1
		elif i is ')':
			current_depth -= 1
		max_depth = max(max_depth, current_depth)
		stack_depth.append(current_depth)
	noted_variables = set()
	variable_mapping = {}
	current_depth = max_depth
	variable_number = 0
	# print(expr)
	for j in range(len(expr)):
		if expr[j] not in noted_variables and expr[j] not in "+-*/()":
			noted_variables.add(expr[j])
			variable_mapping[expr[j]] = "t" + str(variable_number)
			variable_number += 1
		if expr[j] not in "+-*/()":
			expr[j] = variable_mapping[expr[j]]
	# print(expr)	
	in_parentheses = False
	while current_depth >= 1:
		current_expr = ""
		temp = []
		for k in range(len(expr)):
			if in_parentheses and expr[k] is not ')':
				current_expr += expr[k]
			elif in_parentheses and expr[k] is ')':
				in_parentheses = False
				if current_expr not in noted_variables:
					noted_variables.add(current_expr)
					variable_mapping[current_expr] = "t" + str(variable_number)
					variable_number += 1
				temp.append(variable_mapping[current_expr])
				current_expr = ""
			elif expr[k] is '(' and stack_depth[k] == current_depth:
				in_parentheses = True
			else:
				temp.append(expr[k])
		expr = temp
		# print(temp)
		curr_depth_temp = 0
		stack_depth = []
		for i in expr:
			if i is '(':
				curr_depth_temp += 1
			elif i is ')':
				curr_depth_temp -= 1
			stack_depth.append(curr_depth_temp)
		current_depth -= 1
	# print(expr)
	expr_matching = {}
	for k, v in variable_mapping.items():
		expr_matching[v] = k
	print(expr_matching)
	variable_list = list(expr_matching.items())
	variable_list.sort()
	# sorted(variable_list)
	print(variable_list)
	
if __name__ == "__main__":
	main()
