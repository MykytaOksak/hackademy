package stack

type Stack struct {
	data []int
}

func New() *Stack {
	return &Stack{}
}

func (s *Stack) Push(el int) {
	s.data = append(s.data, el)
}

func (s *Stack) Pop() int {
	ret := s.data[len(s.data) - 1]
	s.data = s.data[0:len(s.data) - 1]
	return ret
}