#pragma once

float Constraint(float n, float lower, float upper);

int Constraint(int n, int lower, int upper);
void Swap(int* n1, int* n2);
void Swap(float* n1, float* n2);
bool CheckCollision(int x1, int y1, int width1, int height1, int x2, int y2, int width2, int height2);