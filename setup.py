import git
import os

if __name__ == '__main__':
    if os.path.isdir("./lib/crisp"):
        repo_crisp = git.Repo(path="./lib/crisp")
        repo_crisp.remotes.origin.pull()
    else:
        git.Repo.clone_from(url = "https://github.com/gunnerDgd/crisp", to_path = "./lib/crisp")