#include "Parser.h"

Parser::Parser(int argc, char* argv[]) : _programName(argv[0]){
    for(int i = 1; i < argc; ++i){
        std::string arg = argv[i];
        if (arg.substr(0, 2) == "--"){
            std::size_t equalPos = arg.find('=');
            if (equalPos == std::string::npos){
                if (i + 1 < argc && argv[i + 1][0] != '-'){
                    _args[arg.substr(2)] = argv[++i];   //--option value
                }else{
                    _args[arg.substr(2)] = "";
                }
            }else{
                std::string option = arg.substr(2, equalPos - 2);  //从--后到=前
                std::string value = arg.substr(equalPos + 1);   //=后的全部
                _args[option] = value;
            }
        }else if (arg.substr(0, 1) == "-"){
            if (arg.size() > 2){    //-ovalue
                _args[arg.substr(1, 1)] = arg.substr(2);
            }else{  //-o value
                if (i + 1 < argc && argv[i + 1][0] != '-'){
                    _args[arg.substr(1)] = argv[++i];
                }else{
                    _args[arg.substr(1)] = "";
                }
            }
        }else{
            _positionalArgs.push_back(arg);
        }
    }
}

bool Parser::has(const std::string &name) const{
    return _args.find(name) != _args.end();
}

std::string Parser::get(const std::string &name, const std::string &defaultValue = "") const{
    auto it = _args.find(name);
    if (it != _args.end()){
        return it->second;
    }
    return defaultValue;
}

std::vector<std::string> Parser::getPositionalArgs() const{
    return _positionalArgs;
}

void Parser::printHelp() const{
std::cout << "用法: " << _programName << " [options]\n"
    << "Options:\n"
    << "  -h, --help\t\t显示帮助信息\n"
    << "  -v, --verbose\t\t允许详细输出\n"
    << "  -i, --input FILE\t列出输入文件\n"
    << "  -o, --output FILE\t列出输出文件\n";
}