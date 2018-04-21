module main() {
	difference() {
		union() {
			cube([5, 30, 30]);
			translate([0, 10, 0])
				cube([40, 10, 30]);
			translate([0, 15, 15])
				rotate([45, 0, 0])
					translate([0, -21.21/2, -21.21/2])
						cube([40, 21.21, 21.21]);
		}

		translate([0, 15, 15])
			rotate([0, 90, 0])
				cylinder(d=5, h = 40);
		translate([0, 15, 15])
			rotate([0, 90, 0])
				cylinder(d=10, h = 30);
		for(y = [5, 25])
			for(z = [5, 25])
				translate([0, y, z])
					rotate([0, 90, 0])
						cylinder(d = 3, h = 5);
	}
}

main();
