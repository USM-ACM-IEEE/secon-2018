module articulated_base() {
	difference() {
		union() {
			hull() {
				cube([120, 105, 10]);
				translate([0, 0, 35])
					cube([120, 70, 10]);
			}
		}

		translate([4, 4, -0.1])
			cube([112, 105, 50]);

		#rotate([0, 90, 0]) {
			translate([-5, 100])
				cylinder(d = 4, h = 125);
			translate([-30, 20])
				cylinder(d = 7, h = 125);
			for(offset = [-17.5/2, 17.5/2])
				translate([offset - 30, 40])
					cylinder(d = 3, h = 125);

			for(x = [7.5:10:17.5])
				for(y = [7.5:10:87.5])
					translate([-x, y])
						cylinder(d = 3, h = 125);
		}

		for(z = [7.5:10:37.5])
			for(x = [5:10:120])
				translate([x, 0, z])
					rotate([-90, 0, 0])
						cylinder(d = 3, h = 5);
		
	}
}

articulated_base();
