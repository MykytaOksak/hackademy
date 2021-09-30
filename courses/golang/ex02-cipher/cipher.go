package cipher

type Cipher interface {
	Encode(string) string
	Decode(string) string
}

type Caesar struct {
	code int
}

func NewCaesar() *Caesar {
	return &Caesar{3}
}

func NewShift(shift int) *Caesar {
	if shift > 25 || shift < -25 || shift == 0 {
		return nil
	}
	return &Caesar{shift}
}

func (c Caesar) Encode(msg string) (encodedMsg string) {
	for _, val := range msg {

		if val >= 'A' && val <= 'Z' {
			val += 32
		}
		if val >= 'a' && val <= 'z' {
			val += rune(c.code)

			if val > 'z' {
				val -= 26
			} else if val < 'a' {
				val += 26
			}

			encodedMsg += string(val)
		}
	}

	return encodedMsg
}

func (c Caesar) Decode(codedMsg string) (decodedMsg string) {
	for _, val := range codedMsg {
		val -= rune(c.code)

		if val > 'z' {
			val -= 26
		} else if val < 'a' {
			val += 26
		}

		decodedMsg += string(val)
	}

	return decodedMsg
}


