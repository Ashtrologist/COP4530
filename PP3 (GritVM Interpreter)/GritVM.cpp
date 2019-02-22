#ifndef GRITVM_CPP
#define GRITVM_CPP

#include "GritVM.hpp"

//Constructor
GritVM::GritVM(){
    machineStatus = WAITING;    //The status should start off waiting
    accumulator = 0; //Accumulator should start at 0
}

//Sets the accumulator to 0, clears the dataMem and instructMem, sets the machineStatus to WAITING
STATUS GritVM::reset()
{
    machineStatus = WAITING; 
    accumulator = 0; 
    dataMem.clear(); 
    instructMem.clear(); 

    return machineStatus;
}

//Accessor, gets the data memember
std::vector<long> GritVM::getDataMem(){
    return dataMem;
}

//Load function to load in files
STATUS GritVM::load(const std::string filename, const std::vector<long> &initialMemory){

    if (machineStatus != WAITING ){
        return machineStatus;
    }
       
    ifstream input;
    string line;

//Opens the file
    input.open(filename);
    
   //Ensures that the file is open
    if(!input.good()){
        throw ("For some reason the file is not opening");
    }


    else {
        machineStatus = READY;

        while(getline(input, line)){

            if(line.empty())
                continue;

            if (line[0] == '#')
                continue;
            
            Instruction instructions = GVMHelper::parseInstruction(line);

            if(instructions.operation == UNKNOWN_INSTRUCTION)
                return machineStatus = ERRORED;
            
            instructMem.push_back(GVMHelper::parseInstruction(line));
        }
    }

    dataMem = initialMemory;

    if(instructMem.size() != 0){
        machineStatus = READY;
    }

    else 
        machineStatus = WAITING;
    
    return machineStatus;
}

//This method starts the evaluation of the instructions and returns the machine status
STATUS GritVM::run(){
    switch(machineStatus){
         case WAITING:  
			break;

        case READY:
            machineStatus = RUNNING;
            break;

		case RUNNING:  
			break;

		case HALTED:  
			GritVM::reset(); 
			break;
				
		case ERRORED: 
			GritVM::reset(); 
			break;
		
		case UNKNOWN:  
			GritVM::reset(); 
			break;		
    }

    currentInstruct = instructMem.begin();

    while(machineStatus == RUNNING){
        if (currentInstruct == instructMem.end()){
            machineStatus = HALTED;
        }
    
        switch(currentInstruct -> operation){
            case CLEAR:
                accumulator = 0;
                break;
            
            case AT:
                accumulator = dataMem.at(currentInstruct -> argument);
                break;
            
            case SET:
                dataMem.at(currentInstruct -> argument) = accumulator;
                break;

            case INSERT:
				dataMem.insert(dataMem.begin() + (currentInstruct -> argument), accumulator);				
				break;

			case ERASE:		
				dataMem.erase(dataMem.begin() + currentInstruct -> argument);	
				break;

			case ADDCONST:
				accumulator += currentInstruct -> argument; 
				break;

			case SUBCONST:
				accumulator -= currentInstruct -> argument; 
				break;

			case MULCONST:
				accumulator *= currentInstruct -> argument; 
				break;	

			case DIVCONST:
				accumulator /= currentInstruct -> argument; 
				break;

			case ADDMEM:
				accumulator += dataMem.at(currentInstruct -> argument); 
				break;

			case SUBMEM:
				accumulator -= dataMem.at(currentInstruct -> argument); 
				break;

			case MULMEM:
				accumulator *= dataMem.at(currentInstruct -> argument);
				break;

			case DIVMEM:
				accumulator /= dataMem.at(currentInstruct -> argument); 
				break;

            case JUMPREL:
                if (currentInstruct -> argument < 0){
                    for (int i = currentInstruct -> argument; i <= 0; i++){
                        currentInstruct --;
                    }
                }
                else if ( currentInstruct -> argument == 0){
                    continue;
                }

                else {
                    for (int i =  currentInstruct -> argument; i >= 0; i--){
                        currentInstruct ++;
                    }
                }
                break;
            
            case JUMPZERO:
                if (accumulator == 0){
                    if(currentInstruct -> argument < 0){
                        for (int i = currentInstruct -> argument; i < 0; i++){
                            currentInstruct --;
                        }
                        currentInstruct --;
                    }

                    else {
                        for (int i = currentInstruct -> argument; i > 0; i --){
                            currentInstruct ++;
                        }
                        currentInstruct --;
                    }
                }
                break;

            case JUMPNZERO:
                if(accumulator != 0){
                    if(currentInstruct -> argument < 0){
                        for (int i = currentInstruct -> argument; i < 0; i++){
                            currentInstruct--;
                        }
                        currentInstruct--;
                    }

                    else{
                        for(int i = currentInstruct -> argument; i > 0; i--){
                            currentInstruct ++;
                        }
                        currentInstruct --;
                    }
                }
                break;
            
            case NOOP:
                break;
            
            case HALT:
                machineStatus = HALTED;
                break;
            
            case OUTPUT:
                break;
            
            case CHECKMEM:
                if(int(currentInstruct -> argument) <= int(dataMem.size())){
                    break;
                }

                else machineStatus = ERRORED;

                break;
            
            case UNKNOWN_INSTRUCTION:
                machineStatus = ERRORED;
                break;
            
            default:
                machineStatus = HALTED;
                break;
        }

    currentInstruct ++;

    if(currentInstruct == instructMem.end()){
        machineStatus = HALTED;
    }

 }

    return machineStatus;
}




#endif