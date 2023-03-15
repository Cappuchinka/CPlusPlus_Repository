//
// Created by volch on 14.03.2023.
//

#include "../Headers/Component.h"

Component::Component(int x, int y, int width, int height, bool visible, std::string name) : x{x},
                                                                                            y{y},
                                                                                            width{width},
                                                                                            height{height},
                                                                                            visible{visible},
                                                                                            name{name} {}

Component::Component(bool visible, std::string name) : visible{visible},
                                                       name{name} {}