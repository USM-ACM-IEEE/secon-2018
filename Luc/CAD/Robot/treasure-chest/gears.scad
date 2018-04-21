module small_gear() {
	difference() {
		scale([0.075, 0.075, 1])
			linear_extrude(10) {
				import("gg_gear N10 D1.67 P6 PA20.dxf");
			}

		for(y = [-1, 1])
			translate([0, y*4.5, 0])
				cube([10.5, 1.5, 10], center = true);

		cylinder(d = 3, h = 10, center = true);
		translate([0, 0, 5])
			cylinder(d = 6, h = 10);
	}
}

module big_gear() {
	difference() {
				scale([0.075, 0.075, 1])
			linear_extrude(10) {
				import("gg_gear N20 D3.33 P6 PA20.dxf");
			}

		for(th = [0:45:360])
			for(r = [0, 5, 10, 15, 20])
				rotate([0, 0, th])
					translate([r, 0])
						cylinder(d = 3, h = 10)

		cylinder(d = 3, h = 10);
	}
}

module hemi_gear() {
	difference() {
		union() {
			intersection() {
				scale([0.075, 0.075, 1])
					linear_extrude(10) {
						import("gg_gear N20 D3.33 P6 PA20.dxf");
					}
				translate([-50, 0, 0])
					cube([100, 100, 100]);
			}
			translate([-44/2, -5, 0])
				cube([44, 5, 10]);
		}

		for(th = [0:45:180])
			for(r = [0, 5, 10, 15, 20])
				rotate([0, 0, th])
					translate([r, 0])
						cylinder(d = 3, h = 10)

		cylinder(d = 3, h = 10);
	}
}
small_gear();
//big_gear();
//hemi_gear();
