# Report: Preserving Data Semantics and Chunking Strategies for Structured Candidate Data

## Table of Contents

1. [Use Case Overview](#use-case-overview)
2. [Chunk Definition and Creation](#chunk-definition-and-creation)
   - [Logical Sections for Chunking](#logical-sections-for-chunking)
   - [Creating Chunks](#creating-chunks)
3. [Using LLMs to Summarize Chunks](#using-llms-to-summarize-chunks)
4. [Metadata for Each Selected Chunk](#metadata-for-each-selected-chunk)
5. [Retrieval and Reconstruction of Candidate Profiles](#retrieval-and-reconstruction-of-candidate-profiles)
6. [Conclusion](#conclusion)

---

## Use Case Overview

The candidate data comprises structured fields such as:
- **Personal Information:** First name, last name, gender, DOB, etc.
- **Contact Details:** Email, phone numbers, social links.
- **Professional Summary:** Headline, profile, about the candidate.
- **Employment History and Education:** Company details, positions, degrees, etc.
- **Languages, Skills, and Certifications:** Including proficiency levels and tags.

For high-quality retrieval, it is essential to preserve the inherent semantics of each section. Instead of embedding the entire candidate profile as one monolithic block, we split it into logical sections (chunks) and embed each chunk individually.

---

## Chunk Definition and Creation

### Logical Sections for Chunking

For our use case, a **chunk** is defined as a semantically coherent unit of data extracted from a candidate’s profile. Logical sections that can be chunked include:

1. **Personal Information:** Basic details that identify the candidate.
2. **Employment History:** Each employment entry or aggregated work experience.
3. **Education:** Details about academic qualifications.
4. **Skills and Certifications:** Lists of technical and soft skills, certifications, and language proficiencies.
5. **Profile Summary:** A narrative section describing the candidate’s experience and interests.

### Creating Chunks

**Chunk Creation Process:**

1. **Parsing & Segmentation:**  
   - Extract the candidate’s full profile.
   - Use predetermined rules or parsing libraries (e.g., via LangChain text splitters) to segment the data into the logical sections outlined above.

2. **Handling Long Text:**  
   - For sections with long narratives (like the profile summary), apply recursive or sliding window chunking.
   - This ensures that no critical context is lost by maintaining overlapping segments.

3. **Chunking Granularity:**  
   - Ensure each chunk is of a manageable size (within the token limits of your embedding model) while still preserving contextual integrity.

---

## Using LLMs to Summarize Chunks

**Role of LLMs in Chunk Processing:**

- **Summarization:**  
  - LLMs can be used to generate a concise summary of each chunk, extracting the essential information.  
  - This step helps in normalizing and clarifying the content, ensuring that the vector embedding focuses on the most relevant details.

- **Quality Control:**  
  - The LLM can also assist in reformatting or cleaning the text data before embedding, thus reducing noise.

**Example Workflow:**

1. **Input:** A raw employment history chunk.
2. **LLM Processing:** The LLM summarizes the chunk into key points (e.g., company name, position, duration, key responsibilities).
3. **Output:** A refined text summary that is then embedded into a vector.

---

## Metadata for Each Selected Chunk

Attaching rich metadata to each chunk is essential for enhancing retrieval. Recommended metadata fields include:

- **Candidate ID:** A unique identifier linking all chunks belonging to the same candidate.
- **Section/Field Type:** A label such as `"employment_history"`, `"education"`, `"skills"`, or `"profile_summary"`.
- **Field-Specific Attributes:**  
  - **Employment:** `company_name`, `position`, `working_location`, `duration` (start/end dates).
  - **Education:** `school`, `degree`, `major`, `time_period`.
  - **Skills/Certifications:** `skill_tag`, `certification_name`, `proficiency_level`.
- **Chunk Order/Index:**  
  - Used if a section is split into multiple parts (e.g., `"chunk_index": 1`).
- **Language Tag:**  
  - If applicable (e.g., `"language": "en"` or `"language": "ja"`).
- **Keywords/Summary (Optional):**  
  - A set of key phrases or a brief summary for quick reference.

**Example Metadata for an Employment Chunk:**

```json
{
  "candidate_id": "CAND12345",
  "section": "employment_history",
  "company_name": "MetLife",
  "position": "Senior Architect",
  "working_location": "Tokyo",
  "employment_type": "Full time",
  "duration": "2019-03 to 2022-04",
  "chunk_index": 1,
  "keywords": ["Cloud Architecture", "DevOps", "Leadership"]
}
```

---

## Retrieval and Reconstruction of Candidate Profiles

The retrieval process in the vector database leverages both vector similarity and metadata filters. When a query is made (e.g., "Candidates with 5+ years of experience"), the system:

1. **Searches Relevant Chunks:**  
   - Filters for employment history chunks with the corresponding metadata (e.g., duration or years of experience).

2. **Candidate Reconstruction:**  
   - Uses the unique candidate ID to aggregate all chunks from that candidate.
   - Presents a complete profile that includes employment, education, skills, and any other relevant sections.

This strategy ensures that while the system can pinpoint specific qualifications, it still enables a holistic view of each candidate.

---

## Conclusion

For high-quality candidate retrieval using vector databases, it is advisable to:
- **Segment the candidate profile** into logical, semantically coherent chunks.
- **Apply LLM summarization** to refine and standardize each chunk.
- **Enrich each chunk with detailed metadata** for precise filtering and retrieval.
- **Aggregate chunks using a candidate ID** to reconstruct the full profile as needed.

By implementing these strategies, you can significantly enhance the precision of your candidate searches, allowing recruiters to filter and retrieve profiles based on very specific criteria without losing the overall context.

---


