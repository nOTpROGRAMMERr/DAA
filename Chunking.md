# Candidate Search Optimization Using Chunking and Metadata  

## 1. Introduction  

In this report, we outline an efficient approach for querying thousands of candidate profiles using a structured chunking and metadata approach. The goal is to quickly retrieve relevant candidates while ensuring that their complete profiles remain accessible.  

## 2. Chunk Definition for Candidate Profiles  

Each candidate profile is divided into structured sections (chunks) to enable granular retrieval while maintaining a logical relationship between data points.  

### Sections for Chunking  
Each candidate profile is split into the following sections:  
- **Employment History:** Job roles, companies, responsibilities, and years of experience.  
- **Education:** Degrees, institutions, major fields of study, and graduation year.  
- **Skills & Certifications:** Technical skills, soft skills, and certifications.  
- **Personal Summary:** Overview of the candidate’s professional background.  
- **Additional Information:** Language proficiency, location, social links, etc.  

## 3. Metadata for Chunk Management  

To efficiently search and retrieve relevant candidates, each chunk is enriched with metadata:  

| Metadata Field     | Description |
|-------------------|-------------|
| `candidate_id`    | Unique identifier for the candidate |
| `section`        | Indicates the type of chunk (employment, education, etc.) |
| `company_name`   | (For employment) Name of the employer |
| `position`       | (For employment) Job title |
| `duration`       | (For employment) Years spent in a role |
| `years_of_experience` | Calculated total experience |
| `keywords`       | Extracted key terms (e.g., "machine learning", "project management") |
| `chunk_index`    | If a section is split into multiple chunks, the index for reassembly |
| `language`       | Identifies the language of the chunk (if multilingual) |

### Example Metadata for an Employment Chunk  

```json
{
  "candidate_id": "CAND12345",
  "section": "employment",
  "company_name": "TechCorp",
  "position": "Senior Data Scientist",
  "duration": "2017-2023",
  "years_of_experience": 6,
  "keywords": ["data science", "machine learning", "project management"],
  "chunk_index": 1
}
```

## 4. Using LLM for Summarization  

For longer sections, an LLM is used to summarize content into a fixed token limit (e.g., 200 tokens per chunk). This ensures:  
- **Efficient storage:** Prevents excessively large chunks in vector search.  
- **Consistent retrieval:** Enables better similarity search results.  
- **Controlled response size:** Keeps query responses within manageable token limits.  

## 5. Querying Strategy  

To find a candidate matching a query such as “Senior Data Scientist with experience in Project Management”:  

### Step 1: Filter by Metadata  
- Search for `position` containing "Senior Data Scientist".  
- Ensure `years_of_experience` is ≥ 5.  
- Check `keywords` for "project management".  

### Step 2: Perform Vector Search  
- Use similarity search on the **employment** chunks if metadata filtering is insufficient.  

### Step 3: Retrieve the Complete Profile  
- Once matching employment chunks are identified, retrieve all related chunks using the `candidate_id`.  

## 6. Handling Token Limits  

To maintain efficiency:  
- Each chunk is **limited to 200 tokens**, ensuring vector embeddings remain compact.  
- LLMs **summarize long sections** before storage.  
- Metadata-based filtering **reduces unnecessary vector comparisons**.  

## 7. Benefits of This Approach  

- **Faster Retrieval:** Metadata filtering narrows down results before vector search.  
- **Better Accuracy:** Each chunk represents a focused aspect of a candidate’s profile.  
- **Scalability:** Can efficiently handle thousands of profiles without performance degradation.  

---  

## 8. Conclusion  

By implementing structured chunking, metadata tagging, and token-limited summarization, this approach enables precise and efficient candidate search across large datasets. The combination of metadata filtering and vector search ensures both accuracy and performance.  

