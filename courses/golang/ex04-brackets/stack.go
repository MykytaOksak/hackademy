package brackets

type Stack struct {
	data []string
}

func New() *Stack {
	return &Stack{}
}

func (s *Stack) Push(el string) {
	s.data = append(s.data, el)
}

func (s *Stack) Pop() string {
	if len(s.data) == 0 {
		return ""
	}

	ret := s.data[len(s.data) - 1]
	s.data = s.data[0:len(s.data) - 1]
	
	return ret
}