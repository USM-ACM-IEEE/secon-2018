// TODO: Taper bearing holes
module subWheel(outerDiameter, subWheelDiameter, subWheelLength) {
	render()
		rotate_extrude($fn = 25, convexity = 10)
			intersection() {
				translate([(subWheelDiameter/2)-(outerDiameter/2), 0])
					circle(d = outerDiameter, $fn=100);
				translate([0, -subWheelLength/2])
					square([50, subWheelLength]);
			}
}

module subWheelWithBearingMounts(outerDiameter, subWheelDiameter, subWheelLength) {
	bearingDiameter = 10.5;
	bearingThickness = 4;
	axleDiameter = 4;

	taperHeight = (bearingDiameter-axleDiameter)/2;

	render()
		difference() {
			subWheel(outerDiameter = outerDiameter, subWheelDiameter = subWheelDiameter, subWheelLength = subWheelLength);

			// Bearing Hole
			translate([0, 0, subWheelLength/2 - 2])
				cylinder(d = bearingDiameter, h = bearingThickness, center = true);
			translate([0, 0, -(subWheelLength/2 - 2)])
				cylinder(d = bearingDiameter, h = bearingThickness, center = true);

			// Axle Hole
			cylinder(d = axleDiameter, h = subWheelLength, center = true);

			// Taper
			for(flip = [0,1])
				mirror([0, 0, flip])
					translate([0, 0, subWheelLength/2 - taperHeight - bearingThickness])
						cylinder(d1 = axleDiameter, d2 = bearingDiameter, h = taperHeight);
		}
}

module subWheelAssembly(outerDiameter, subWheelDiameter, subWheelLength) {
	for(theta = [0:90:270])
		rotate([0, theta, 0])
			translate([outerDiameter/2 - subWheelDiameter/2, 0])
				subWheel(outerDiameter = outerDiameter, subWheelDiameter = subWheelDiameter, subWheelLength = subWheelLength);
}

module subWheelAssemblyWithBearingMounts(outerDiameter, subWheelDiameter, subWheelLength) {
	for(theta = [0:90:270])
		rotate([0, theta, 0])
			translate([outerDiameter/2 - subWheelDiameter/2, 0])
				subWheelWithBearingMounts(outerDiameter = outerDiameter, subWheelDiameter = subWheelDiameter, subWheelLength = subWheelLength);
}

module wheel(outerDiameter, subWheelDiameter, subWheelLength) {
	
	// Carriage
	width = outerDiameter - 5;
	difference() {
		rotate([90, 0, 0]) {
			intersection() {
				cube([width, width, subWheelDiameter], center = true);
				cylinder(d = outerDiameter - 5, h = subWheelDiameter/2, center = true);
			}
		}

		subWheelAssembly(outerDiameter = outerDiameter, subWheelDiameter = subWheelDiameter + 2, subWheelLength = subWheelLength + 2);

		// Mounting Holes
		rotate([90, 0, 0]) {
			cylinder(d = 15, h = subWheelDiameter, center = true);
			for(x = [-15/2, 15/2])
				for(y = [-15/2, 15/2])
					translate([x, y])
						cylinder(d = 3.5, h = subWheelDiameter, center = true);
		}
		for(theta = [0:90:270])
			rotate([0, theta, 0])
				translate([outerDiameter/2 - subWheelDiameter/2, 0]) {
					cylinder(d = 3.5, h = 42.8, center = true);
					translate([0, 0, 42.8/2])
						cylinder(d = 6, h = 2.8*2, center = true);
					translate([0, 0, -42.8/2])
						cylinder(d = 6.5, h = 2.25*2, center = true, $fn=6);
				}
	}
}

module wheelAssembly(outerDiameter, subWheelDiameter, subWheelLength) {
	translate([0, -subWheelDiameter/2]) {
		wheel(outerDiameter = outerDiameter, subWheelDiameter = subWheelDiameter, subWheelLength = subWheelLength);
		subWheelAssembly(outerDiameter = outerDiameter, subWheelDiameter = subWheelDiameter, subWheelLength = subWheelLength);
		for(theta = [0:90:270])
			rotate([0, theta, 0])
				translate([outerDiameter/2 - subWheelDiameter/2, 0]) {
					cylinder(d = 3, h = 42.8, center = true);
					translate([0, 0, 42.8/2])
						cylinder(d = 6, h = 2.8*2, center = true);
					translate([0, 0, -42.8/2])
						cylinder(d = 6.5, h = 2.25*2, center = true, $fn=6);
				}
	}
		
	translate([0, subWheelDiameter/2])
		rotate([0, 45, 0]) {
			wheel(outerDiameter = outerDiameter, subWheelDiameter = subWheelDiameter, subWheelLength = subWheelLength);
			subWheelAssembly(outerDiameter = outerDiameter, subWheelDiameter = subWheelDiameter, subWheelLength = subWheelLength);
			for(theta = [0:90:270])
				rotate([0, theta, 0])
					translate([outerDiameter/2 - subWheelDiameter/2, 0]) {
						cylinder(d = 3, h = 42.8, center = true);
						translate([0, 0, 42.8/2 - 2.8/2])
							cylinder(d = 6, h = 2.8, center = true);
						translate([0, 0, -42.8/2 + 2.25/2])
							cylinder(d = 6.5, h = 2.25, center = true, $fn=6);
					}
		}
}

module spacer(subWheelDiameter) {
	difference() {
		hull() {
		for(x = [-15/2, 15/2])
			for(y = [-15/2, 15/2])
				for(theta = [0, 45])
					rotate([0, 0, theta])
						translate([x, y])
							cylinder(d=6, h=subWheelDiameter/2, center=true);
		}
		cylinder(d = 15, h = subWheelDiameter/2, center = true);
		for(x = [-15/2, 15/2])
			for(y = [-15/2, 15/2])
				for(theta = [0, 45])
					rotate([0, 0, theta])
						translate([x, y])
							cylinder(d=3, h=subWheelDiameter/2, center=true);
	}
}

module wheelMount(subWheelDiameter) {
	difference() {
		union() {
			hull() {
				for(x = [-15/2, 15/2])
					for(y = [-15/2, 15/2])
						for(theta = [0])
							rotate([0, 0, theta])
								translate([x, y, -15/2])
									cylinder(d=8, h=15/2);
			}

			cylinder(d = 14, h = 15/2);
		}

		for(x = [-15/2, 15/2])
			for(y = [-15/2, 15/2])
				for(theta = [0])
					rotate([0, 0, theta])
						translate([x, y, -15/2]) {
							cylinder(d=3, h=15/2);
							cylinder(d=7, h=3.5);
						}

		cylinder(d = 5.5, h = 100, center = true);

		translate([0, 0, -15/4])
			rotate([90, 0, 0])
				cylinder(d = 3, h = 30);
	}
}


//wheelAssembly(outerDiameter=50, subWheelDiameter=14, subWheelLength=17.5);
//wheelAssembly(outerDiameter=64, subWheelDiameter=18, subWheelLength=27);

//spacer(subWheelDiameter = 20);
wheelMount();
//wheelAssembly(outerDiameter=70, subWheelDiameter=20, subWheelLength=30);
//wheel(outerDiameter=70, subWheelDiameter=20, subWheelLength=30);
//subWheelAssembly(outerDiameter=70, subWheelDiameter=20, subWheelLength=30);
//subWheelWithBearingMounts(outerDiameter=70, subWheelDiameter=20, subWheelLength=30);

//wheelAssembly(outerDiameter=90, subWheelDiameter=25, subWheelLength=40);
