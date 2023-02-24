#pragma once
namespace sputils {
	class Vector3 {
		public:
		double x, y, z;
		Vector3(double x = 0, double y = 0, double z = 0):x(x),y(y),z(z) {

		}
		/*double& operator .(int index) {
			switch(index) {
				case x:
					return x;
					break;
				case y:
					return y;
					break;
				case z:
					return z;
					break;
				default:
					break;
			}
		}*/
	};

}