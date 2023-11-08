type Water struct {
	temperature int
}

func NewWater(a int) Water {
	var res Water
	res.temperature = a
	return res
}

type Teapot struct {
	water Water
}

func (tea Teapot) is_boiling() bool {
	if tea.water.temperature >= 100 {
		return true
	} else {
		return false
	}
}
func (tea *Teapot) heat_up(a int) {
	(*tea).water.temperature += a
}

func NewTeapot(a Water) Teapot {
	var res Teapot
	res.water = a
	return res
}