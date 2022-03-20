# try random ordering of projects
# prioritize mentoring
# works for e f

import math
import random
import copy

skill_ids = {}
skill_names = []
those = []

class Coder:
    # skills: id -> level
    def __init__(self, name, skills):
        self.name = name
        self.skills = skills
        self.avail = 0

    def learn(self, id):
        self.skills.setdefault(id, 0)
        those[id][self.skills[id]].remove(self)
        self.skills[id] = min(100, self.skills[id] + 1)
        those[id][self.skills[id]].add(self)

    def get_skill(self, id):
        return self.skills.get(id, 0)

class Project:
    # req: list[(id, level)]
    def __init__(self, name, req, duration, ddl, value):
        self.name = name
        self.req = req
        self.coders = [None] * len(req)
        self.duration = duration
        self.ddl = ddl
        self.value = value

    def score(self, coders):
        assert len(coders) == len(self.req)
        best_skills = {}
        for coder in coders:
            for k, v in coder.skills.items():
                best_skills[k] = max(best_skills.get(k, 0), v)
        # mentor
        for i, (skill, level) in enumerate(self.req):
            coder = coders[i]
            mentor = best_skills.get(skill, 0) >= level
            assert coder.get_skill(skill) + mentor >= level
            if mentor and coder.get_skill(skill) == level - 1:
                coder.learn(skill)
        self.coders = coders
        start = max([coder.avail for coder in coders])
        end = start + self.duration
        for coder in self.coders:
            coder.avail = end
        return max(1, self.value - max(0, end - self.ddl))

    def assign(self, coders):
        s = self.score(coders)
        assert s > 0
        self.coders = coders
        return s
    
def best_candidate(skill, level):
    for l in range(level, 101):
        if those[skill][level]:
            best = None
            min_avail = int(1e9)
            for candidate in those[skill][level]:
                if candidate.avail < min_avail:
                    min_avail = candidate.avail
                    best = candidate
            return best
    return None

def solve_project_sequence(projects):
    score = 0
    project_solved = 0
    for project in projects:
        best_skills = {}
        coders = []
        for skill, level in project.req:
            mentor = best_skills.get(skill, 0) >= level
            # find coder with the minimum level
            candidate = best_candidate(skill, level - mentor)
            if candidate is None:
                break
            for k, v in candidate.skills.items():
                best_skills[k] = max(best_skills.get(k, 0), v)
            coders.append(candidate)
        if len(coders) == len(project.req):
            score += project.assign(coders)
            project_solved += 1
    # print(f"score: {score}, project_solved: {project_solved}")
    return score

def read_coder():
    name, n = input().split()
    n = int(n)
    skills = {}
    for i in range(n):
        k, v = input().split()
        v = int(v)
        if k not in skill_ids:
            skill_ids[k] = len(skill_ids)
            skill_names.append(k)
            those.append([set() for _ in range(101)])
        skills[skill_ids[k]] = v
    coder = Coder(name, skills)
    for k, v in skills.items():
        those[k][v].add(coder)
    return coder

def read_project():
    name, d, s, b, r = input().split()
    d, s, b, r = int(d), int(s), int(b), int(r)
    req = []
    for i in range(r):
        k, v = input().split()
        v = int(v)
        assert k in skill_ids
        req.append((skill_ids[k], v))
    return Project(name, req, d, b, s)
    
def reset(coders):
    global those
    those = [[set() for _ in range(101)] for __ in range(len(skill_ids))]
    for coder in coders:
        for k, v in coder.skills.items():
            those[k][v].add(coder)

def heur(project):
    return project.value / (project.duration)

def shuffle(l, swaps=1):
    n = len(l)
    for _ in range(swaps):
        i = random.randint(0, n - 2)
        l[i], l[i + 1] = l[i + 1], l[i]

def main():
    # read input
    m, n = map(int, input().split())
    coders, projects = [], []
    for i in range(m):
        coders.append(read_coder())
    for i in range(n):
        projects.append(read_project())

    # sort projects by heuristic
    projects.sort(key=heur, reverse=True)

    # for pro in projects:
    #     print(heur(pro), end=", ")
    # print()

    best_score = 0
    for i in range(1000):
        coders_copy = copy.deepcopy(coders)
        reset(coders_copy)
        shuffle(projects, swaps=2)
        score = solve_project_sequence(projects)
        print(score)
        if score > best_score:
            best_score = score
            print("best:", best_score)
    

if __name__ == "__main__":
    main()
        
# shuffle then try solve some order of projects
