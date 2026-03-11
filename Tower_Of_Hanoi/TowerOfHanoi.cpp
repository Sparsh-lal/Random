#include <bits/stdc++.h>

// using namespace std;

namespace sparsh{
    // class cube
	class cube{
		public:
            // custom constructor
            cube(double length){ length_ = length; }

            // class functions
			void setLength(double length){ length_ = length; }
			double getLength() const { return length_; }
			double getVolume() const { return length_ * length_ * length_; }
			double getSurfaceArea() const { return 6 * length_ * length_; }
			
		private:
			double length_;
			int color_;
	};

    // class stack
    class stack{
		public:
            // class functions
			void push_back(const cube& cube){ cubes_.push_back(cube); }
			unsigned size(){ return cubes_.size(); }

            cube& peekTop(){
                if(cubes_.empty()) std::runtime_error("peekTop on empty stack");
                return cubes_.back(); 
            }

			cube removeTop(){
                if(cubes_.empty()) std::runtime_error("removeTop on empty stack");
                cube c = cubes_.back();
                cubes_.pop_back();
                return c;
            }
			
			// overloading operator
            friend std::ostream& operator<<(std::ostream& os, const stack& stack);
			
		private:
			std::vector<cube> cubes_;
	};

    // class game
    class game{
		public:
            // custom constructor
            game(int n){
                // create three empty stacks
                for(int i=0; i<3; ++i){
                    stack stackOfCubes;
                    stacks_.push_back(stackOfCubes);
                }
                
                // inputting the cubes
                for(int i=0; i<n; ++i){
                    double length; std::cin >> length;
                    cube c(length);
                    stacks_[0].push_back(c);
                }
            }

            // class functions

			void _move(unsigned i, unsigned j){
                cube c = stacks_[i].removeTop();
                stacks_[j].push_back(c);
            }
            
            void _legalMove(unsigned i, unsigned j, int n){
                if(stacks_[i].size() == 0 && stacks_[j].size() > 0){ _move(j, i); }
                else if(stacks_[i].size() > 0 && stacks_[j].size() == 0){ _move(i, j); }
                else if(stacks_[i].size() > 0 && stacks_[j].size() > 0){
                    if(stacks_[i].peekTop().getLength() < stacks_[j].peekTop().getLength()){ _move(i, j); }
                    else { _move(j, i); }
                }
                
                if(stacks_[2].size() != n){ std::cout << *this << std::endl; }
            }

            void solve(int n){
                while(stacks_[2].size() != n){
                    _legalMove(0, 1, n);
                    _legalMove(0, 2, n);
                    _legalMove(1, 2, n);
                }
            }
            
            // overloading opertor to print game state:
            friend std::ostream& operator<<(std::ostream& os, const sparsh::game& game);

		private:
			std::vector<stack> stacks_;
	};

    // overloading opertor to print stack:
    std::ostream& operator<<(std::ostream& os, const stack& stack){
        for(const auto& cube : stack.cubes_){ os << cube.getLength() << " "; }
        return os;
    }

    // overloading opertor to print game state:
    std::ostream& operator<<(std::ostream& os, const sparsh::game& game){
        for(int i=0; i<3; ++i){ os << "Tower " << i << ": " << game.stacks_[i] << "\n"; }
        return os;
    }
}

int main(){
    int n; std::cin >> n;

	sparsh::game g(n);
	
	std::cout << "Initial Game State: " << std::endl;
	std::cout << g << std::endl;
	
	g.solve(n);
	
	std::cout << "Final Game State: " << std::endl;
	std::cout << g << std::endl;
	
	return 0;
}