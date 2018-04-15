module main(length = 50) {
	difference() {
		union() {
			cube([5, 30, 10]);
			translate([5, 10, 0])
				cube([length, 10, 10]);
			translate([5+length, 0, 0])
				cube([5, 30, 10]);
		}

		for(y = [5, 25])
			translate([0, y, 5])
				rotate([0, 90, 0])
					cylinder(d = 3, h = 10 + length);
	}
}

main();
