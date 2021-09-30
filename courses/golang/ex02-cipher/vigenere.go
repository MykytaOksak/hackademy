package cipher

type Vigenere struct {
	key string
}

func NewVigenere(key string) *Vigenere {
	invalidKey, onlyAaa := false, true
	for _, char := range key {
		if !(char >= 'a' && char <= 'z') {
			invalidKey = true
			break
		} else if char != 'a' {
			onlyAaa = false
		}
	}

	if invalidKey || onlyAaa {
		return nil
	} else if key == "" {
		return &Vigenere{"akeyofonehundredcharacters"}
	}

	return &Vigenere{key}
}

func (v Vigenere) getKey(msgLen int) string {
	retKey := v.key
	initialLen := len(v.key)
	keyLen := initialLen

	for msgLen > keyLen {
		retKey += v.key
		keyLen += initialLen
	}
	return retKey[:msgLen]
}

func cleanMsg(msg string) string {
	cleanMsg := ""
	for _, val := range msg {
		if val >= 'A' && val <= 'Z' {
			cleanMsg += string(val + 32)
		} else if val >= 'a' && val <= 'z' {
			cleanMsg += string(val)
		}
	}

	return cleanMsg
}

func (v Vigenere) Encode(msg string) (encodedMsg string) {
	msg = cleanMsg(msg)
	key := v.getKey(len(msg))

	for i, val := range msg {
		if val >= 'a' && val <= 'z' {
			encodedMsg += string(rune((rune(key[i]-'a')+rune(msg[i]-'a'))%26 + 'a'))
		}
	}

	return encodedMsg
}

func (v Vigenere) Decode(encodedMsg string) (decodedMsg string) {
	key := v.getKey(len(encodedMsg))
	for i := range encodedMsg {
		decodedMsg += string(rune((rune(encodedMsg[i]-'a')+26-rune(key[i]-'a'))%26 + 'a'))
	}

	return decodedMsg
}
