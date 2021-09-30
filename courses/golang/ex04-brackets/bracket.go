package brackets

func areMatched(open, close string) bool {
	switch open + close {
	case "{}", "[]", "()":
		return true
	default:
		return false
	}
}

func Bracket(brackets string) (bool, error) {
	bracketsStack := New()

	for _, v := range brackets {
		switch v {
		case '{', '[', '(':
			bracketsStack.Push(string(v))
		case '}', ']', ')':
			s := bracketsStack.Pop()
			if !areMatched(s, string(v)) {
				return false, nil
			}
		}
	}
	return len(bracketsStack.data) == 0, nil
}