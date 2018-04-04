	for(th = [0:1:270])
		hull() {
			rotate([0,0,th])
				cube([th, 1, 1]);
			rotate([0,0,th+1])
				cube([th+1, 1, 1]);
		}
