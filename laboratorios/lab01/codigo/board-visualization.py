import pygame

combinations = []

def iterate_combinations():
    global combinations
    obtained_result = False
    c_temp = combinations.copy()
    for c in combinations:
        for i in range(len(c)-1):
            this_char = c[i]
            next_char = c[i+1]
            if this_char=='v' and next_char=='v':
                new_combination = ""
                for j in range(len(c)):
                    if j!=i and j!=i+1:
                        new_combination += c[j]
                    else:
                        new_combination += "h"
                if not new_combination in combinations and not new_combination in c_temp:
                    c_temp.append(new_combination)
                    obtained_result = True
    combinations = c_temp
    return obtained_result



def initialize_combinations(n):
    global combinations
    combinations = []
    base = ""
    for i in range(n):
        base += "v"
    combinations.append(base)

def create_all_combinations():
    global combinations
    while iterate_combinations():
        print(combinations, len(combinations))

zoom = 1
c_x = 100
c_y = 0

def from_hsva(h,s,l,a):
    color = pygame.Color(0)
    color.hsla = h,s,l,a
    return color

def draw_fixed(surface, color, rect):
    new_rect = ((rect[0] + c_x) * zoom, (rect[1] + c_y) * zoom, rect[2] * zoom, rect[3] * zoom)
    pygame.draw.rect(surface, color, new_rect, 1)

def draw_with_depth(surface, color, rect, depth):
    new_rect = ((rect[0] + depth), (rect[1] + depth) , rect[2] - depth * 2, rect[3] - depth * 2)
    draw_fixed(surface, color, new_rect)

def draw_vertical_rect(surface, color, n, depth):
    rect = (100 * n, 300, 100, 200)
    draw_with_depth(surface, color, rect, depth)

def draw_horizontal_rects(surface, color, n, depth):
    rect_a = (100 * n, 300, 200, 100)
    rect_b = (100 * n, 400, 200, 100)
    draw_with_depth(surface, color, rect_a, depth)
    draw_with_depth(surface, color, rect_b, depth)

n = 1

def status_text (font):
    global n
    global combinations
    text = "n: " + str(n) + " result: " + str(len(combinations))
    text_res = font.render(text, True, (205, 205, 205))
    return text_res

def reset_calculations():
    global text_res
    global n
    global font
    initialize_combinations(n)
    create_all_combinations()
    text_res = status_text(font)


def visualize():
    global n
    global font
    global text_res
    pygame.init()
    pygame.font.init()
    font = pygame.font.SysFont('Inconsolata', 23)
    pygame.display.set_caption("Board visualization")
    screen = pygame.display.set_mode((1000, 700))
    reset_calculations()
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    if n < 8:
                        n+=1
                        reset_calculations()
                elif event.key == pygame.K_DOWN:
                    if n > 1:
                        n-=1
                        reset_calculations()
        screen.fill((34, 34, 34))
        for i in range(len(combinations)):
            this_comb = combinations[i]
            this_hue = (360 / len(combinations)) * i
            this_depth = (45 / len(combinations)) * i
            this_color = from_hsva(this_hue, 63.2, 67.1, 100)
            drawn_previous = False
            for j in range(len(this_comb)):
                this_char = this_comb[j]
                if j < len(this_comb) -1:
                    next_char = this_comb[j + 1]
                    if this_char == "h" and next_char == "h":
                        if not drawn_previous:
                            draw_horizontal_rects(screen, this_color,j,this_depth)
                            drawn_previous = True
                        else:
                            drawn_previous = False
                if this_char == "v":
                    draw_vertical_rect(screen, this_color,j,this_depth)
        screen.blit(text_res, (10, 10))
        pygame.display.flip()

visualize()
