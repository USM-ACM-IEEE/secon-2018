module main() {
	difference() {
		union() {
			translate([0, 0, -2.5])
				cube([130, 130, 5], center = true);
		}

		// Motor Mount
		for(th = [0:90:270])
			rotate([0, 0, th])
				translate([50, 0, 42/2])
					rotate([0, 90, 0]) {
						cylinder(d = 23, h = 100, center = true);
						for(x = [-31/2, 31/2])
							for(y = [-31/2, 31/2])
								translate([x, y])
									cylinder(d = 3, h = 100, center = true);
					}

		// Grid
		for(x = [-60:10:60])
			for(y = [-60:10:60])
				translate([x, y, 0])
					cylinder(d = 3, h = 10, center = true);
		for(x = [-40:40:40])
			for(y = [-40:40:40])
				translate([x, y, 0])
					cylinder(d = 12, h = 10, center = true);
	}
}

main();
