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

module bar() {
	difference() {
		cube([130, 30, 5]);

		for(x = [5:10:145])
			for(y = [5:10:55])
				translate([x, y, z])
					cylinder(d = 3, h = 10);
	}
}

module sidePiece() {
	difference() {
		union() {
			hull() {
				translate([0, 100, 5]) 
					rotate([0, 90, 0])
						cylinder(d = 10, h = 5);
				translate([0, 5+3, -25/2 + 30])
					cube([5, 70, 25]);

				translate([0,0,52.5])
					cube([5, 35, 5]);
				translate([0, -5, 20])
					cube([5, 5, 35]);

				translate([0, 37.5, 7.5]) 
					rotate([0, 90, 0])
						cylinder(d = 10, h = 5);
			}
			translate([0, -5, 20])
				cube([25, 5, 35]);
			translate([0, -5, 52.5])
				hull() {
					cube([5, 40, 5]);
					cube([25, 5, 5]);
				}
		}

		rotate([0, 90, 0]) {
			translate([-5, 100])
				cylinder(d = 4, h = 125);
			for(y = [37.5:10:57.5])
				translate([-7.5, y])
					cylinder(d = 3, h = 125);
		}

		for(z = [7.5:10:47.5])
			for(x = [5:10:120])
				translate([x+5, -5, z])
					rotate([-90, 0, 0])
						cylinder(d = 3, h = 5);

		translate([-1, 5+3, 30])
			rotate([90, 0, 90])
				union() {
					translate([15, 0])
						cylinder(d = 12, h = 6);

					translate([15+20, 17.5/2])
						cylinder(d = 3, h = 6);
					translate([15+20, -17.5/2])
						cylinder(d = 3, h = 6);

					translate([15+20+7.5, -15/2])
						cube([25, 15, 6]);
				}
	}
}

//bar();
sidePiece();
//articulated_base();
