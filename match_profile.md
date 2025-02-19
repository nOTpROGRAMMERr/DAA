# Overview
This project utilizes the CrewAI framework to automate the process of extracting relevant information from CVs and matching them to job opportunities. The system consists of several agents that perform specific tasks, such as reading CVs, parsing job descriptions, and matching candidates to job roles based on their qualifications.

# Components
## Libraries Used
- **crewai**: A framework for building intelligent agents.
- **crewai_tools**: Tools for reading files and searching CSV data.

## Key Classes
- **Agent**: Represents an intelligent agent with a specific role and goal.
- **Task**: Defines a specific task that an agent will perform.
- **Crew**: Manages a group of agents and their tasks.
- **Process**: Defines the execution order of tasks (sequential or parallel).

# Installation
To use this code, ensure you have the necessary libraries installed. You can install them via pip:

```bash
pip install crewai crewai_tools
```

# Usage
## Create Language Models (LLMs)
Two language models are instantiated with different configurations to handle various tasks.

```python
llm = LLM(model="groq/llama-3.1-8b-instant", temperature=0.5)
llm_2 = LLM(model="groq/llama-3.3-70b-versatile", temperature=0.5)
```

## Define Agents
- **agent_1** is responsible for extracting information from CVs.
- **agent_2** matches CVs to job opportunities based on skills and experience.

```python
agent_1 = Agent(
    role="cv_reader",
    goal="Extract relevant information from the CV...",
    backstory="With years of experience in HR...",
    tools=[FileReadTool()],
    verbose=True,
    allow_delegation=True,
    llm=llm,
)

agent_2 = Agent(
    role="Matcher",
    goal="Match the CV to the job opportunities...",
    backstory="A seasoned recruiter...",
    tools=[FileReadTool(), CSVSearchTool()],
    verbose=True,
    allow_delegation=False,
    llm=llm_2,
)
```

## Define Tasks
Each agent is assigned a task with a description and expected output.

```python
task_1 = Task(
    description='''Extract relevant information from the given CV...''',
    expected_output='''A structured summary of the CV...''',
    agent=agent_1
)

task_2 = Task(
    description='''Match the CV to the job opportunities...''',
    expected_output='''A ranked list of job opportunities...''',
    agent=agent_3,
    output_file='output/match_profile_rish_crewai.md'
)
```

## Create a Crew
Combine agents and tasks into a crew for execution.

```python
crew = Crew(
    agents=[agent_1, agent_2],
    tasks=[task_1, task_2],
    verbose=True,
    process=Process.sequential,
)
```

## Run the Crew
Provide input paths for the CV and jobs CSV file, then execute the crew.

```python
inputs = {
    'path_to_jobs_csv': './src/misc/data/jobs.csv',
    'path_to_cv': './knowledge/rish.md'
}

result = crew.kickoff(inputs=inputs)
print(result)
```

# Input Files
- **CV File**: Path to the CV file (e.g., `./knowledge/rish.md`).
- **Jobs CSV File**: Path to the CSV file containing job descriptions (e.g., `./src/misc/data/jobs.csv`).

# Expected Output
The output will include:
- A structured summary of the CV detailing professional summary, technical skills, work history, education, and key achievements.
- A ranked list of job opportunities that best match the CV, including job title, match score based on skills and experience, and key matching points.

# Conclusion
This project provides a streamlined approach to resume parsing and job matching using intelligent agents. By leveraging AI capabilities, it enhances recruitment processes and improves candidate-job alignment.
