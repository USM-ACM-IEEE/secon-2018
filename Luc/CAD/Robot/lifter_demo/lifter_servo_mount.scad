module main() {
	difference() {
		union() {
			hull() {
				for(y = [-5, 5, 15])
					translate([-5, y])
						cylinder(d = 10, h = 20);
			}
			hull() {
				translate([-5, 5])
					cylinder(d = 10, h = 20);
				cube([10, 10, 20]);
			}
		}

		for(y = [-5, 5, 15])
			translate([-5, y]) {
				cylinder(d = 3.5, h = 20);
				translate([0, 0, 15])
					cylinder(d = 7, h = 5);
			}

		for(z = [5, 15])
			translate([30-24, 0, z])
				rotate([-90, 0, 0])
					cylinder(d = 3, h = 10);
	}
}

main();
