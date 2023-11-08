type Cat struct {
	live int64
}

type Box struct {
	cat Cat
}

func (cat Cat) is_alive() bool {
	if cat.live == 1 {
		return true
	} else {
		return false
	}
}

func (box Box) open() Cat {
	if box.cat.live < 1 {
		rand.Seed(time.Now().UnixNano())
		box.cat.live = rand.Int63()%2 + 1
	}
	return box.cat
}