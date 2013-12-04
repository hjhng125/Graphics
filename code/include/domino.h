#ifndef _DOMINO
#define _DOMINO

//domino class

class domino
{
	private:
		double x;//x position
		double y;//y position
		double norm;//forward vector angle from positive x axis in radians
		double tilt;//angle of tilt in radians
		int load;//number of dominoes resting on it
		bool standing;//whether or not the domino is standing
		bool resting;//whether of not the domino is resting
		domino* support;//domino it is resting on
		
	public:
		//constructor
		domino(double xpos, double ypos, double forward)
		{
			x = xpos;
			y = ypos;
			norm = forward;
			standing = true;
			resting = false;
			support = NULL;
			load = 0;
		}
		
		//get the x position
		double getX()
		{
			return x;
		}
		
		//get the y position
		double getY()
		{
			return y;
		}
		
		//get the norm angle
		double getNorm()
		{
			return norm;
		}
		
		//get the tilt angle
		double getTilt()
		{
			return tilt;
		}
		
		//get the standing status
		bool isStanding()
		{
			return standing;
		}
		
		//add resting dominues
		int getLoad()
		{
			return load;
		}
		
		//timestep
		bool step()
		{
			if(!resting)
			{
				//falling
				double speed = tilt/M_PI*180 + 10*load; 
				tilt += speed/180.0*M_PI/60.0;
				//cout << speed << endl;
				if(tilt >= M_PI/2)
				{
					tilt = M_PI/2;
				}
				//collision detection
				if(sin(tilt)*0.75*25 >= 10 -.75*5)
				{
					return true;
				}
			}
			else
			{
				if(support != NULL)
				{
					double w = sqrt((x - support -> getX())*(x - support -> getX()) + (y - support -> getY())*(y - support -> getY()));
					double theta = asin(w*cos(support -> getTilt())/2)+support -> getTilt();
					tilt = theta;
				}
				else if(tilt > 90/180*M_PI)
				{
					tilt = 90/180*M_PI;
				}
			}
			
			return false;
		}
		
		void reset()
		{
			tilt = 0;
			load = 0;
			standing = true;
			resting = false;
			support = NULL;
		}
		
		void setSupport(domino *supporter)
		{
			support = supporter;
		}
		
		void start(int number)
		{
			load = number;
			if(load == 0)
			{
				tilt = 1.0/180*M_PI;
			}
			standing = false;
		}
		
		void drawline()
		{  
		   glBegin(GL_LINES);
			  glVertex3f(x-5*cos(norm+(M_PI/2)), y-5*sin(norm+(M_PI/2)), 0.0);
			  glVertex3f(x+5*cos(norm+(M_PI/2)), y+5*sin(norm+(M_PI/2)), 0.0);
		   glEnd();
		}
		
		void rest(domino* supporter)
		{
			resting = true;
			support = supporter;
		}
		
		void rest()
		{
			resting = true;
		}
};

#endif
