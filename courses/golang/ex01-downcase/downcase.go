package downcase

func Downcase(s string) (string, error) {
	var res string
	for _, sym := range s {
		if sym <= 90 && sym >= 65 {
			res = res + string(sym+32)
		} else {
			res = res + string(sym)
		}
	} 
	return res, nil
}
