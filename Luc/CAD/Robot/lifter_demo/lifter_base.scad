module base() {
	difference() {
		cube([100 - 10, 75, 30]);

		translate([5, 5, 5])
			cube([100 - 10 - 10, 75 - 5 + 0.1, 30 - 5 + 0.1]);
		translate([0, 5, 25])
			cube([100 - 10 + 0.1, 75 - 5 + 0.1, 5 + 0.1]);


		// Hinge hole
		translate([0, 15, 15])
			rotate([0, 90, 0])
				cylinder(d = 3, h = 100 - 10);

		// Mount holes
		for(x = [5:10:85])
			for(z = [5:10:25])
				translate([x, 0, z])
					rotate([-90, 0, 0])
						cylinder(d = 3, h = 15);

		// Mount holes
		for(x = [5:10:85])
			for(y = [10:10:90])
				translate([x, y, 0])
					cylinder(d = 3, h = 5);
	}
}

module attachment() {
	difference() {
		hull() {
			translate([0, 20, 0])
				cube([100, 75-20, 10]);
			translate([0, 0, 20])
				cube([100, 75, 10]);
		}

		// Hinge hole
		translate([0, 15, 15])
			rotate([0, 90, 0])
				cylinder(d = 4, h = 120 - 10);

		translate([5 - 1, 0, 5])
			cube([100 - 10 + 2, 75, 30 - 5]);
		#translate([5 - 1, 0, 0])
			cube([100 - 10 + 2, 30, 30]);
		translate([5 - 1, 0, 0])
			cube([100 - 10 + 2, 10, 20 - 5]);

		// Mount holes
		for(x = [5:10:95])
			for(y = [10:10:90])
				translate([x, y, 0])
					cylinder(d = 3, h = 5);
	}
}


//rotate([0, 180, 0])
//	translate([-90/2, -10, -30/2])
//		base();


rotate([-$t*15, 0, 0])
	render()
		translate([-100/2, -10, -30/2])
			attachment();
